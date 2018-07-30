//
// Created by Mishin870 on 30.07.2018.
//

#include "CmdElse.h"
#include "../../engine/ScriptLoader.h"

CmdElse::CmdElse(Stream *stream) {
	this->command = loadCommand(stream);
}

CmdElse::~CmdElse() {
	delete this->command;
}

Object *CmdElse::execute(Engine *engine) {
	Object* object = this->command->execute(engine);
	delete object;
	return nullptr;
}

CommandType CmdElse::getType() {
	return CT_ELSE;
}
