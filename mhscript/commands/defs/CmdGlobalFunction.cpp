//
// Created by Mishin870 on 31.07.2018.
//

#include "CmdGlobalFunction.h"
#include "../../engine/ScriptLoader.h"
#include "../ScriptUtils.h"

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
	Object** arguments = new Object*[this->argsCount];
	unsigned int i;
	for (i = 0; i < this->argsCount; i++) {
		arguments[i] = getPureObject(this->args[i]->execute(engine));
	}
	if (this->isGlobal) {
		return engine->executeGlobalFunction(this->functionName, arguments, this->argsCount);
	} else {
		return engine->executeLocalFunction(this->functionName, arguments, this->argsCount);
	}
}

CommandType CmdGlobalFunction::getType() {
	return CT_GLOBAL_FUNCTION;
}
