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
	if (executeBool(this->condition, engine)) {
		executeVoid(this->command, engine);
	} else {
		unsigned int i;
		for (i = 0; i < this->elseStatementsCount; i++) {
			CommandType type = this->elseStatements[i]->getType();
			switch (type) {
				case CT_ELSE:
					executeVoid(this->elseStatements[i], engine);
					return nullptr;
				case CT_ELSE_IF:
					if (executeBool(this->elseStatements[i], engine)) {
						return nullptr;
					}
				default:
					throw std::runtime_error("CmdIf::execute => unknown else statement type!");
			}
		}
	}
	return nullptr;
}

CommandType CmdIf::getType() {
	return CT_IF;
}
