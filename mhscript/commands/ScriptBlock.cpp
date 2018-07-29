//
// Created by Mishin870 on 28.07.2018.
//

#include "ScriptBlock.h"
#include "../engine/ScriptLoader.h"

ScriptBlock::ScriptBlock(unsigned int commandsCount, ICommand** commands, unsigned int functionsCount, LocalFunction** functions) {
	this->commands = commands;
	this->commandsCount = commandsCount;
	this->functions = functions;
	this->functionsCount = functionsCount;
}

ScriptBlock::ScriptBlock(Stream *stream) {
	this->commands = loadBlock(stream, this->commandsCount);
	bool isRoot = stream->readByte() == 1;
	if (isRoot) {
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

Object *ScriptBlock::execute(Engine *engine) {
	//TODO: add local functions to engine
	
	unsigned int i;
	for (i = 0; i < this->commandsCount; i++) {
		this->commands[i]->execute(engine);
	}
}

CommandType ScriptBlock::getType() {
	return CT_SCRIPT_BLOCK;
}
