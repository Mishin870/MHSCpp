//
// Created by Mishin870 on 28.07.2018.
//

#ifndef MHSCPP_ENGINE_H
#define MHSCPP_ENGINE_H


#include "Variable.h"
#include "../stream/Stream.h"
#include "../commands/LocalFunction.h"

class ScriptBlock;
class LocalFunction;

class Engine {
	public:
		Engine();
		~Engine();
		
		Variable* getVariable(unsigned int variableName);
		void setLocalFunction(unsigned int localFunctionName, LocalFunction* localFunction);
		ScriptBlock* loadCurrentScript(Stream *stream);
	private:
		ScriptBlock* currentScript;
		void dispose();
		
		unsigned int variablesCount;
		Variable** variables;
		
		unsigned int localFunctionsCount;
		LocalFunction** localFunctions;
};


#endif //MHSCPP_ENGINE_H
