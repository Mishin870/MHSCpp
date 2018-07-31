//
// Created by Mishin870 on 31.07.2018.
//

#include <stdexcept>
#include "CmdGlobalFunction.h"
#include "../../engine/ScriptLoader.h"
#include "../ScriptUtils.h"
#include "../../objects/ObjectBool.h"

CmdGlobalFunction::CmdGlobalFunction(Stream *stream) {
	this->isGlobal = stream->readByte() == 1;
	this->functionName = stream->readInt();
	this->args = loadBlock(stream, this->argsCount);
}

CmdGlobalFunction::~CmdGlobalFunction() {
	unsigned int i;
	for (i = 0; i < this->argsCount; i++) {
		delete this->args[i];
	}
	delete[] this->args;
}

Object *CmdGlobalFunction::execute(Engine *engine) {
	//execute function
	return nullptr;
}

CommandType CmdGlobalFunction::getType() {
	return CT_GLOBAL_FUNCTION;
}
