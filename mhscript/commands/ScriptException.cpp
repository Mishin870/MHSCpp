//
// Created by Mishin870 on 30.07.2018.
//

#include "ScriptException.h"
#include "ScriptExceptionType.h"

ScriptException::ScriptException(char const* message, ScriptExceptionType type, Object* data) : std::runtime_error(message) {
	this->type = type;
	this->data = data;
}

ScriptException::ScriptException(ScriptExceptionType type, Object* data) : std::runtime_error("") {
	this->type = type;
	this->data = data;
}

ScriptException::~ScriptException() {
	delete this->data;
}

char const *ScriptException::what() const throw() {
	return runtime_error::what();
}

Object *ScriptException::getData() {
	return this->data;
}

ScriptExceptionType ScriptException::getType() {
	return this->type;
}
