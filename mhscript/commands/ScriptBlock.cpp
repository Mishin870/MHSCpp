//
// Created by Mishin870 on 28.07.2018.
//

#include "ScriptBlock.h"
#include "../engine/ScriptLoader.h"
#include "ScriptUtils.h"

ScriptBlock::ScriptBlock(Stream *stream) {
	this->commands = loadBlock(stream, this->commandsCount);
	this->isRoot = stream->readByte() == 1;
	if (this->isRoot) {
		this->functionsCount = stream->readInt();
		this->functions = new LocalFunction*[this->functionsCount];
		unsigned int i;
		for (i = 0; i < this->functionsCount; i++) {
			this->functions[i] = new LocalFunction(stream);
		}
	} else {
		this->functionsCount = 0;
		this->functions = nullptr;
	}
}

ScriptBlock::~ScriptBlock() {
	unsigned int i;
	for (i = 0; i < this->commandsCount; i++) {
		delete this->commands[i];
	}
	delete[] this->commands;
	
	if (this->isRoot) {
		for (i = 0; i < this->functionsCount; i++) {
			delete this->functions[i];
		}
		delete[] this->functions;
	}
}

Object *ScriptBlock::execute(Engine *engine) {
	unsigned int i;
	if (this->isRoot) {
		for (i = 0; i < this->functionsCount; i++) {
			LocalFunction* function = this->functions[i];
			engine->setLocalFunction(function->getName(), function);
		}
	}
	
	for (i = 0; i < this->commandsCount; i++) {
		executeVoid(this->commands[i], engine);
	}
	return nullptr;
}

CommandType ScriptBlock::getType() {
	return CT_SCRIPT_BLOCK;
}
