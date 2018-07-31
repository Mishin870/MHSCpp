//
// Created by Mishin870 on 31.07.2018.
//

#include "CmdEmpty.h"
#include "../../engine/ScriptLoader.h"

CmdEmpty::CmdEmpty(Stream *stream) {}

CmdEmpty::~CmdEmpty() {}

Object *CmdEmpty::execute(Engine *engine) {
	return nullptr;
}

CommandType CmdEmpty::getType() {
	return CT_EMPTY;
}