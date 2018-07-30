//
// Created by Mishin870 on 30.07.2018.
//

#include "ScriptException.h"
#include "ScriptExceptionType.h"

ScriptException::ScriptException(char const* message, ScriptExceptionType type, Object* data) : std::runtime_error(message) {
	this->type = type;
	this->data = data;
}

char const *ScriptException::what() const {
	return runtime_error::what();
}
