//
// Created by Mishin870 on 01.08.2018.
//

#include "CallArgs.h"

CallArgs::CallArgs(FunctionType functionType) {
	this->functionType = functionType;
}

CallArgs::~CallArgs() {
	std::map<unsigned int, Variable*>::iterator iter;
	for (iter = this->variables.begin(); iter != this->variables.end(); iter++) {
		delete (*iter).second;
	}
	this->variables.clear();
}

void CallArgs::setVariable(unsigned int variableName, Variable *variable) {
	this->variables.insert(std::pair<unsigned char, Variable*>(variableName, variable));
}
