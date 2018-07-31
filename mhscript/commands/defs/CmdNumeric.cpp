//
// Created by Mishin870 on 31.07.2018.
//

#include "CmdNumeric.h"
#include "../../engine/ScriptLoader.h"
#include "../../objects/ObjectInt.h"

CmdNumeric::CmdNumeric(Stream *stream) {
	this->value = stream->readInt();
}

CmdNumeric::~CmdNumeric() {}

Object *CmdNumeric::execute(Engine *engine) {
	return new ObjectInt(this->value);
}

CommandType CmdNumeric::getType() {
	return CT_NUMERIC;
}
