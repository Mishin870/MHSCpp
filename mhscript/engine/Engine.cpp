//
// Created by Mishin870 on 28.07.2018.
//

#include <stdexcept>
#include <iostream>
#include "Engine.h"
#include "ScriptLoader.h"

Engine::Engine() {
	this->variables = nullptr;
	this->variablesCount = 0;
	this->localFunctions = nullptr;
	this->localFunctionsCount = 0;
	this->currentScript = nullptr;
	this->callStackPointer = 0;
}

void Engine::loadCurrentScript(Stream *stream) {
	if (this->currentScript != nullptr) {
		dispose();
	}
	
	bool optimized = stream->readByte() == 1;
	if (!optimized) {
		throw std::runtime_error("Script is not optimized for the client interpreter!");
	}
	
	unsigned int count, len, i;
	count = stream->readInt();
	this->globalFunctionsCount = count;
	this->globalFunctionNames = new std::string[this->globalFunctionsCount];
	for (i = 0; i < count; i++) {
		len = stream->readInt();
		this->globalFunctionNames[i].resize(len);
		stream->readString(this->globalFunctionNames[i]);
	}
	count = stream->readInt();
	this->localFunctionsCount = count;
	this->localFunctionNames = new std::string[this->localFunctionsCount];
	for (i = 0; i < count; i++) {
		len = stream->readInt();
		this->localFunctionNames[i].resize(len);
		stream->readString(this->localFunctionNames[i]);
	}
	count = stream->readInt();
	this->variablesCount = count;
	this->variableNames = new std::string[this->variablesCount];
	for (i = 0; i < count; i++) {
		len = stream->readInt();
		this->variableNames[i].resize(len);
		stream->readString(this->variableNames[i]);
	}
	
	this->globalFunctions = new IGlobalFunction*[this->globalFunctionsCount];
	this->localFunctions = new LocalFunction*[this->localFunctionsCount];
	this->variables = new Variable*[this->variablesCount];
	for (i = 0; i < this->variablesCount; i++) {
		this->variables[i] = new Variable(nullptr);
	}
	for (i = 0; i < this->localFunctionsCount; i++) {
		this->localFunctions[i] = nullptr;
	}
	
	ICommand* script = loadCommand(stream);
	if (script->getType() != CT_SCRIPT_BLOCK) {
		throw std::runtime_error("Main script block must have type CT_SCRIPT_BLOCK!");
	}
	this->currentScript = dynamic_cast<ScriptBlock*>(script);
}

void Engine::executeCurrentScript() {
	this->currentScript->execute(this);
}

void Engine::dispose() {
	//Script also deletes local functions
	delete this->currentScript;
	
	unsigned int i;
	for (i = 0; i < this->variablesCount; i++) {
		delete this->variables[i];
		//delete this->variableNames[i];
	}
	delete[] this->variables;
	delete[] this->variableNames;
	
	for (i = 0; i < this->globalFunctionsCount; i++) {
		delete this->globalFunctions[i];
		//delete this->globalFunctionNames[i];
	}
	delete[] this->globalFunctions;
	delete[] this->globalFunctionNames;
	
	/*for (i = 0; i < this->localFunctionsCount; i++) {
		delete this->localFunctionNames[i];
	}*/
	delete[] this->localFunctions;
	delete[] this->localFunctionNames;
}

Engine::~Engine() {
	if (this->currentScript != nullptr) {
		dispose();
	}
}

Variable *Engine::getVariable(unsigned int variableName) {
	unsigned int index = callStackPointer - 1;
	if (callStackPointer > 0 && callStack[index]->functionType == LOCAL && callStack[index]->variables.count(variableName) > 0) {
		return callStack[index]->variables[variableName];
	} else {
		return this->variables[variableName];
	}
}

void Engine::setLocalFunction(unsigned int localFunctionName, LocalFunction* localFunction) {
	if (localFunctionName < 0 || localFunctionName >= this->localFunctionsCount) {
		throw std::runtime_error("Engine::setLocalFunction => out of range!");
	}
	this->localFunctions[localFunctionName] = localFunction;
}

void Engine::setGlobalFunction(unsigned int globalFunctionName, IGlobalFunction *globalFunction) {
	if (globalFunctionName < 0 || globalFunctionName >= this->globalFunctionsCount) {
		throw std::runtime_error("Engine::setGlobalFunction => out of range!");
	}
	this->globalFunctions[globalFunctionName] = globalFunction;
}

Object* Engine::executeLocalFunction(unsigned int functionName, Object** args, unsigned int argc) {
	if (functionName < 0 || functionName >= this->localFunctionsCount) {
		throw std::runtime_error("Engine::executeLocalFunction => out of range!");
	}
	CallArgs* callArgs = new CallArgs(LOCAL);
	LocalFunction* localFunction = this->localFunctions[functionName];
	unsigned int i;
	for (i = 0; i < localFunction->argsCount; i++) {
		Variable* variable = new Variable(args[i]);
		callArgs->setVariable(localFunction->args[i], variable);
	}
	addToCallStack(callArgs);
	Object* result = localFunction->execute(this);
	removeFromCallStack();
	delete[] args;
	
	return result;
}

Object* Engine::executeGlobalFunction(unsigned int functionName, Object** args, unsigned int argc) {
	if (functionName < 0 || functionName >= this->globalFunctionsCount) {
		throw std::runtime_error("Engine::executeGlobalFunction => out of range!");
	}
	CallArgs* callArgs = new CallArgs(GLOBAL);
	addToCallStack(callArgs);
	Object* result = this->globalFunctions[functionName]->execute(args, argc);
	removeFromCallStack();
	
	unsigned int i;
	for (i = 0; i < argc; i++) {
		delete args[i];
	}
	delete[] args;
	
	return result;
}

unsigned int Engine::getGlobalFunctionNameByString(std::string name) {
	unsigned int i;
	for (i = 0; i < this->globalFunctionsCount; i++) {
		if (this->globalFunctionNames[i] == name) {
			return i;
		}
	}
	return CANT_FIND;
}

unsigned int Engine::getLocalFunctionNameByString(std::string name) {
	unsigned int i;
	for (i = 0; i < this->localFunctionsCount; i++) {
		if (this->localFunctionNames[i] == name) {
			return i;
		}
	}
	return CANT_FIND;
}

unsigned int Engine::getVariableByNameString(std::string name) {
	unsigned int i;
	for (i = 0; i < this->variablesCount; i++) {
		if (this->variableNames[i] == name) {
			return i;
		}
	}
	return CANT_FIND;
}

void Engine::addToCallStack(CallArgs* args) {
	callStack.push_back(args);
	callStackPointer++;
}

void Engine::removeFromCallStack() {
	if (callStackPointer == 0) {
		throw std::runtime_error("Engine::removeFromCallStack => call stack is empty!");
	}
	delete callStack[callStackPointer - 1];
	callStack.pop_back();
	callStackPointer--;
}
