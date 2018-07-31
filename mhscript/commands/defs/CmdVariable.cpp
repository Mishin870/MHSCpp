//
// Created by Mishin870 on 31.07.2018.
//

#include "CmdVariable.h"
#include "../../engine/ScriptLoader.h"

CmdVariable::CmdVariable(Stream *stream) {
	this->variableName = stream->readInt();
}

CmdVariable::~CmdVariable() {}

Object *CmdVariable::execute(Engine *engine) {
	return engine->getVariable(this->variableName);
}

CommandType CmdVariable::getType() {
	return CT_VARIABLE;
}
