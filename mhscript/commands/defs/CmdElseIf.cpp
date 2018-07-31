//
// Created by Mishin870 on 31.07.2018.
//

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
	if (executeBool(this->condition, engine)) {
		executeVoid(this->command, engine);
		return new ObjectBool(true);
	} else {
		return new ObjectBool(false);
	}
}

CommandType CmdElseIf::getType() {
	return CT_ELSE_IF;
}
