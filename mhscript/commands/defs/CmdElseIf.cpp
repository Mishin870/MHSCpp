//
// Created by Mishin870 on 31.07.2018.
//

#include <stdexcept>
#include "CmdElseIf.h"
#include "../../engine/ScriptLoader.h"
#include "../ScriptUtils.h"
#include "../../objects/ObjectBool.h"

CmdElseIf::CmdElseIf(Stream *stream) {
	this->condition = loadCommand(stream);
	this->command = loadCommand(stream);
}

CmdElseIf::~CmdElseIf() {
	delete this->condition;
	delete this->command;
}

Object *CmdElseIf::execute(Engine *engine) {
	Object* condition = this->condition->execute(engine);
	if (getBoolOrCrash(condition)) {
		Object* object = this->command->execute(engine);
		delete object;
	}
	delete condition;
}

CommandType CmdElseIf::getType() {
	return CT_ELSE_IF;
}
