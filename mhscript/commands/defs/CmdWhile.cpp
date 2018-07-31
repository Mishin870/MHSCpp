//
// Created by Mishin870 on 31.07.2018.
//

#include "CmdWhile.h"
#include "../../engine/ScriptLoader.h"
#include "../ScriptUtils.h"

CmdWhile::CmdWhile(Stream *stream) {
	this->condition = loadCommand(stream);
	this->command = loadCommand(stream);
}

CmdWhile::~CmdWhile() {
	delete this->condition;
	delete this->command;
}

Object *CmdWhile::execute(Engine *engine) {
	while (executeBool(this->condition, engine)) {
		executeVoid(this->command, engine);
	}
	
	return nullptr;
}

CommandType CmdWhile::getType() {
	return CT_WHILE;
}