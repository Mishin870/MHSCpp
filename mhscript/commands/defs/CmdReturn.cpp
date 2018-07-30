//
// Created by Mishin870 on 30.07.2018.
//

#include "CmdReturn.h"
#include "../../engine/ScriptLoader.h"
#include "../ScriptException.h"

CmdReturn::CmdReturn(Stream *stream) {
	this->command = loadCommand(stream);
}

CmdReturn::~CmdReturn() {
	delete this->command;
}

Object *CmdReturn::execute(Engine *engine) {
	throw ScriptException(nullptr, ET_RETURN, this->command->execute(engine));
}

CommandType CmdReturn::getType() {
	return CT_RETURN;
}
