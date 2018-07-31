//
// Created by Mishin870 on 28.07.2018.
//

#include <stdexcept>
#include "Engine.h"
#include "ScriptLoader.h"

Engine::Engine() {
	this->variables = nullptr;
	this->variablesCount = 0;
	this->localFunctions = nullptr;
	this->localFunctionsCount = 0;
	this->currentScript = nullptr;
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
	for (i = 0; i < count; i++) {
		len = stream->readInt();
		stream->skip(len);
	}
	count = stream->readInt();
	this->localFunctionsCount = count;
	for (i = 0; i < count; i++) {
		len = stream->readInt();
		stream->skip(len);
	}
	count = stream->readInt();
	this->variablesCount = count;
	for (i = 0; i < count; i++) {
		len = stream->readInt();
		stream->skip(len);
	}
	
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
	}
	delete[] this->variables;
	
	delete[] this->localFunctions;
}

Engine::~Engine() {
	if (this->currentScript != nullptr) {
		dispose();
	}
}

Variable *Engine::getVariable(unsigned int variableName) {
	return this->variables[variableName];
}

void Engine::setLocalFunction(unsigned int localFunctionName, LocalFunction* localFunction) {
	if (localFunctionName >= this->localFunctionsCount) {
		throw std::runtime_error("Engine::setLocalFunction => out of range!");
	}
	this->localFunctions[localFunctionName] = localFunction;
}

void Engine::setGlobalFunction(unsigned int globalFunctionName, IGlobalFunction *globalFunction) {
	if (globalFunctionName >= this->localFunctionsCount) {
		throw std::runtime_error("Engine::setLocalFunction => out of range!");
	}
	this->globalFunctions[globalFunctionName] = globalFunction;
}

Object* Engine::executeLocalFunction(unsigned int functionName, Object** args, unsigned int argc) {

}

Object* Engine::executeGlobalFunction(unsigned int functionName, Object** args, unsigned int argc) {
	this->globalFunctions[functionName]->execute(args, argc);
}