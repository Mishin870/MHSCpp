//
// Created by Mishin870 on 31.07.2018.
//

#include <stdexcept>
#include "CmdIf.h"
#include "../../engine/ScriptLoader.h"
#include "../ScriptUtils.h"

CmdIf::CmdIf(Stream *stream) {
	this->condition = loadCommand(stream);
	this->command = loadCommand(stream);
	this->elseStatements = loadBlock(stream, this->elseStatementsCount);
}

CmdIf::~CmdIf() {
	delete this->condition;
	delete this->command;
	
	unsigned int i;
	for (i = 0; i < this->elseStatementsCount; i++) {
		delete this->elseStatements[i];
	}
	delete[] this->elseStatements;
}

Object *CmdIf::execute(Engine *engine) {
	Object* object = condition->execute(engine);
	Object* object2;
	
	if (getBoolOrCrash(object)) {
		object2 = command->execute(engine);
		delete object2;
	} else {
		unsigned int i;
		for (i = 0; i < this->elseStatementsCount; i++) {
			CommandType type = this->elseStatements[i]->getType();
			switch (type) {
				case CT_ELSE:
					object2 = this->elseStatements[i]->execute(engine);
					delete object2;
					delete object;
					return nullptr;
				case CT_ELSE_IF:
					object2 = this->elseStatements[i]->execute(engine);
					if (getBoolOrCrash(object2)) {
						delete object;
						delete object2;
						return nullptr;
					} else {
						delete object2;
					}
				default:
					throw std::runtime_error("CmdIf::execute => unknown else statement type!");
			}
		}
	}
	delete object;
	return nullptr;
}

CommandType CmdIf::getType() {
	return CT_IF;
}
