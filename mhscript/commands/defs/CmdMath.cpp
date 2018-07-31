//
// Created by Mishin870 on 31.07.2018.
//

#include <stdexcept>
#include "CmdMath.h"
#include "../../engine/ScriptLoader.h"
#include "../ScriptUtils.h"
#include "../../objects/ObjectInt.h"

CmdMath::CmdMath(Stream *stream) {
	this->operation = static_cast<LexemKind>(stream->readByte());
	this->blocks = loadBlock(stream, this->blocksCount);
}

CmdMath::~CmdMath() {
	unsigned int i;
	for (i = 0; i < this->blocksCount; i++) {
		delete this->blocks[i];
	}
	delete[] this->blocks;
}

Object *CmdMath::execute(Engine *engine) {
	if (this->blocksCount == 0) {
		throw std::runtime_error("CmdMath::execute => no blocks!");
	}
	
	int result = executeInt(this->blocks[0], engine);
	unsigned int i;
	for (i = 1; i < this->blocksCount; i++) {
		switch (this->operation) {
			case PLUS:
				result += executeInt(this->blocks[i], engine);
				break;
			case MINUS:
				result -= executeInt(this->blocks[i], engine);
				break;
			case MULTIPLY:
				result *= executeInt(this->blocks[i], engine);
				break;
			case DIVIDE:
				result /= executeInt(this->blocks[i], engine);
				break;
			default:
				throw std::runtime_error("CmdMath::execute => unknown operation!");
		}
	}
	return new ObjectInt(result);
}

CommandType CmdMath::getType() {
	return CT_MATH;
}
