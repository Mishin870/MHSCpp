//
// Created by Mishin870 on 28.07.2018.
//

#ifndef MHSCPP_LOCALFUNCTION_H
#define MHSCPP_LOCALFUNCTION_H


#include "ScriptBlock.h"
#include "../stream/Stream.h"

class ScriptBlock;

class LocalFunction {
	public:
		explicit LocalFunction(Stream* stream);
		~LocalFunction();
		Object* execute(Engine* engine);
		unsigned int getName();
		
	private:
		unsigned int name;
		ScriptBlock* code;
		unsigned int* args;
		unsigned int argsCount;
};


#endif //MHSCPP_LOCALFUNCTION_H
