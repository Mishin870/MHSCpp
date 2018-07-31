//
// Created by Mishin870 on 31.07.2018.
//

#include <stdexcept>
#include "CmdFor.h"
#include "../../engine/ScriptLoader.h"
#include "../ScriptUtils.h"
#include "../../objects/ObjectBool.h"

CmdFor::CmdFor(Stream *stream) {
	this->condition = loadCommand(stream);
	this->pre = loadCommand(stream);
	this->iter = loadCommand(stream);
	this->command = loadCommand(stream);
}

CmdFor::~CmdFor() {
	delete this->condition;
	delete this->pre;
	delete this->iter;
	delete this->command;
}

Object *CmdFor::execute(Engine *engine) {
	for (executeVoid(this->pre, engine); executeBool(this->condition, engine); executeVoid(this->iter, engine)) {
		executeVoid(this->command, engine);
	}
	
	return nullptr;
}

CommandType CmdFor::getType() {
	return CT_FOR;
}