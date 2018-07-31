//
// Created by Mishin870 on 28.07.2018.
//

#ifndef MHSCPP_LOCALFUNCTION_H
#define MHSCPP_LOCALFUNCTION_H

#include "ICommand.h"
#include "../stream/Stream.h"

class Engine;
class ICommand;

class LocalFunction {
	public:
		explicit LocalFunction(Stream* stream);
		~LocalFunction();
		Object* execute(Engine* engine);
		unsigned int getName();
		
	private:
		unsigned int name;
		ICommand* code;
		unsigned int* args;
		unsigned int argsCount;
};


#endif //MHSCPP_LOCALFUNCTION_H
