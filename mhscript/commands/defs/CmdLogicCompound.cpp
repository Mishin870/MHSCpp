//
// Created by Mishin870 on 30.07.2018.
//

#include <stdexcept>
#include "CmdLogicCompound.h"
#include "../../engine/ScriptLoader.h"
#include "../ScriptUtils.h"
#include "../../objects/ObjectBool.h"

CmdLogicCompound::CmdLogicCompound(Stream *stream) {
	this->operation = static_cast<LexemKind>(stream->readByte());
	this->blocks = loadBlock(stream, this->blocksCount);
}

CmdLogicCompound::~CmdLogicCompound() {
	unsigned int i;
	for (i = 0; i < this->blocksCount; i++) {
		delete this->blocks[i];
	}
	delete[] this->blocks;
}

Object *CmdLogicCompound::execute(Engine *engine) {
	unsigned int i;
	Object* object;
	if (this->operation == AND) {
		for (i = 0; i < this->blocksCount; i++) {
			object = this->blocks[i]->execute(engine);
			bool value = getBool(object);
			delete object;
			if (!value) {
				return new ObjectBool(false);
			}
		}
		return new ObjectBool(true);
	} else if (this->operation == OR) {
		for (i = 0; i < this->blocksCount; i++) {
			object = this->blocks[i]->execute(engine);
			bool value = getBool(object);
			delete object;
			if (value) {
				return new ObjectBool(true);
			}
		}
		return new ObjectBool(false);
	} else {
		throw std::runtime_error("Incorrect operation type in CmdLogicCompound::execute!");
	}
}

CommandType CmdLogicCompound::getType() {
	return CT_LOGIC_COMPOUND;
}
