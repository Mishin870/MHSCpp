//
// Created by Mishin870 on 28.07.2018.
//

#include <stdexcept>
#include "LocalFunction.h"
#include "../engine/ScriptLoader.h"

LocalFunction::LocalFunction(unsigned int name, ScriptBlock *code, unsigned int argsCount, unsigned int *args) {
	this->name = name;
	this->code = code;
	this->argsCount = argsCount;
	this->args = args;
}

LocalFunction::LocalFunction(Stream *stream) {
	this->name = stream->readInt();
	
	ICommand* block = loadCommand(stream);
	if (block->getType() != CT_SCRIPT_BLOCK) {
		throw std::runtime_error("Local function block must have type SCRIPT_BLOCK!");
	}
	this->code = dynamic_cast<ScriptBlock*>(block);
	
	this->argsCount = stream->readInt();
	unsigned int i;
	this->args = new unsigned int[this->argsCount];
	for (i = 0; i < this->argsCount; i++) {
		this->args[i] = stream->readInt();
	}
}
