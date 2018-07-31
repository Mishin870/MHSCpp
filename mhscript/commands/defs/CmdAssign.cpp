//
// Created by Mishin870 on 31.07.2018.
//

#include <stdexcept>
#include "CmdAssign.h"
#include "../../engine/ScriptLoader.h"
#include "../ScriptUtils.h"

CmdAssign::CmdAssign(Stream *stream) {
	this->left = loadCommand(stream);
	this->right = loadCommand(stream);
}

CmdAssign::~CmdAssign() {
	delete this->left;
	delete this->right;
}

Object *CmdAssign::execute(Engine *engine) {
	if (this->left->getType() == CT_VARIABLE) {
		Variable* variable = getVariableOrCrash(this->left->execute(engine));
		
		//Because the value of the variable will be overriden
		delete variable->value;
		
		variable->value = this->right->execute(engine);
	} else {
		throw std::runtime_error("CmdAssign::execute => unknown type of variable!");
	}
}

CommandType CmdAssign::getType() {
	return CT_ASSIGN;
}
