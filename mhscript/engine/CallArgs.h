//
// Created by Mishin870 on 01.08.2018.
//

#ifndef MHSCPP_CALLARGS_H
#define MHSCPP_CALLARGS_H


#include <map>
#include "FunctionType.h"
#include "Variable.h"

class CallArgs {
	public:
		explicit CallArgs(FunctionType functionType);
		~CallArgs();
		
		void setVariable(unsigned int variableName, Variable* variable);
		
		FunctionType functionType;
		std::map<unsigned int, Variable*> variables;
};


#endif //MHSCPP_CALLARGS_H
