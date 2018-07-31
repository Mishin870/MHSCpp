//
// Created by Mishin870 on 28.07.2018.
//

#include <stdexcept>
#include "LocalFunction.h"
#include "../engine/ScriptLoader.h"
#include "ScriptException.h"

LocalFunction::LocalFunction(Stream *stream) {
	this->name = stream->readInt();
	
	ICommand* block = loadCommand(stream);
	if (block->getType() != CT_SCRIPT_BLOCK) {
		throw std::runtime_error("Local function block must have type SCRIPT_BLOCK!");
	}
	this->code = block;
	
	this->argsCount = stream->readInt();
	unsigned int i;
	this->args = new unsigned int[this->argsCount];
	for (i = 0; i < this->argsCount; i++) {
		this->args[i] = stream->readInt();
	}
}

LocalFunction::~LocalFunction() {
	delete[] this->args;
	delete this->code;
}

Object *LocalFunction::execute(Engine *engine) {
	try {
		this->code->execute(engine);
	} catch (ScriptException se) {
		if (se.getType() == ET_RETURN) {
			return se.getData();
		} else {
			throw std::runtime_error("LocalFunction::execute => unknown type of ScriptException!");
		}
	}
	return nullptr;
}

unsigned int LocalFunction::getName() {
	return this->name;
}
