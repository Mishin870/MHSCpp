//
// Created by Mishin870 on 31.07.2018.
//

#include <stdexcept>
#include "CmdUnary.h"
#include "../../engine/ScriptLoader.h"
#include "../ScriptUtils.h"
#include "../../objects/ObjectBool.h"
#include "../../objects/ObjectInt.h"

CmdUnary::CmdUnary(Stream *stream) {
	this->command = loadCommand(stream);
	this->operation = static_cast<LexemKind>(stream->readByte());
}

CmdUnary::~CmdUnary() {
	delete this->command;
}

Object *CmdUnary::execute(Engine *engine) {
	int x;
	Variable* variable;
	
	switch (this->operation) {
		case INCREMENT:
		case DECREMENT:
		case PREINCREMENT:
		case PREDECREMENT:
			variable = executeVariable(command, engine);
			x = getIntOrCrash(variable);
			break;
		case NOT:
			return new ObjectBool(!executeBool(this->command, engine));
		default:
			throw std::runtime_error("CmdUnary::execute => unknown operation!");
	}
	
	switch (this->operation) {
		case INCREMENT:
			setIntVariable(variable, x + 1);
			return new ObjectInt(x);
		case DECREMENT:
			setIntVariable(variable, x - 1);
			return new ObjectInt(x);
		case PREINCREMENT:
			setIntVariable(variable, x + 1);
			return new ObjectInt(x + 1);
		case PREDECREMENT:
			setIntVariable(variable, x - 1);
			return new ObjectInt(x - 1);
		default:
			throw std::runtime_error("CmdUnary::execute => statement that will never runs!");
	}
}

CommandType CmdUnary::getType() {
	return CT_UNARY;
}
