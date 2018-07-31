//
// Created by Mishin870 on 31.07.2018.
//

#include "CmdBool.h"
#include "../../engine/ScriptLoader.h"
#include "../../objects/ObjectBool.h"

CmdBool::CmdBool(Stream *stream) {
	this->value = stream->readByte() == 1;
}

CmdBool::~CmdBool() {}

Object *CmdBool::execute(Engine *engine) {
	return new ObjectBool(this->value);
}

CommandType CmdBool::getType() {
	return CT_BOOL;
}
