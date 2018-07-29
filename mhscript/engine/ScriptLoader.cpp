//
// Created by Mishin870 on 28.07.2018.
//

#include <stdexcept>
#include <iostream>
#include "ScriptLoader.h"

ScriptBlock* loadScript(Stream* stream) {
	bool optimized = stream->readByte() == 1;
	if (!optimized) {
		throw std::runtime_error("Script is not optimized for client interpreter!");
	}
	
	unsigned int count, len, i;
	count = stream->readInt();
	for (i = 0; i < count; i++) {
		len = stream->readInt();
		stream->skip(len);
	}
	count = stream->readInt();
	for (i = 0; i < count; i++) {
		len = stream->readInt();
		stream->skip(len);
	}
	count = stream->readInt();
	for (i = 0; i < count; i++) {
		len = stream->readInt();
		stream->skip(len);
	}
	
	ICommand* script = loadCommand(stream);
	if (script->getType() != CT_SCRIPT_BLOCK) {
		throw std::runtime_error("Main script block must have type CT_SCRIPT_BLOCK!");
	}
	return dynamic_cast<ScriptBlock*>(script);
}

ICommand* loadCommand(Stream* stream) {
	CommandType type = static_cast<CommandType>(stream->readByte());
	switch (type) {
		case CT_SCRIPT_BLOCK:
			return new ScriptBlock(stream);
		default:
			throw std::runtime_error("Not supported command type in ScriptLoader::loadCommand!");
	}
}

ICommand** loadBlock(Stream* stream, unsigned int &count) {
	unsigned int blocksCount = stream->readInt();
	count = blocksCount;
	ICommand** blocks = new ICommand*[blocksCount];
	unsigned int i;
	for (i = 0; i < blocksCount; i++) {
		blocks[i] = loadCommand(stream);
	}
	return blocks;
}