//
// Created by Mishin870 on 30.07.2018.
//

#ifndef MHSCPP_SCRIPTEXCEPTION_H
#define MHSCPP_SCRIPTEXCEPTION_H


#include <stdexcept>
#include "ScriptExceptionType.h"
#include "../objects/Object.h"

class ScriptException : public std::runtime_error {
	public:
		ScriptException(char const* message, ScriptExceptionType type, Object* data) throw();
		~ScriptException();
		char const* what() const throw() override;
	private:
		ScriptExceptionType type;
		Object* data;
};


#endif //MHSCPP_SCRIPTEXCEPTION_H
