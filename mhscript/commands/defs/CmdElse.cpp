//
// Created by Mishin870 on 30.07.2018.
//

#include "CmdElse.h"
#include "../../engine/ScriptLoader.h"
#include "../ScriptUtils.h"

CmdElse::CmdElse(Stream *stream) {
	this->command = loadCommand(stream);
}

CmdElse::~CmdElse() {
	delete this->command;
}

Object *CmdElse::execute(Engine *engine) {
	executeVoid(this->command, engine);
	return nullptr;
}

CommandType CmdElse::getType() {
	return CT_ELSE;
}
