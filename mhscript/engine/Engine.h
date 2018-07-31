//
// Created by Mishin870 on 28.07.2018.
//

#ifndef MHSCPP_ENGINE_H
#define MHSCPP_ENGINE_H


#include "Variable.h"
#include "../stream/Stream.h"
#include "../commands/LocalFunction.h"
#include "IGlobalFunction.h"

class ScriptBlock;
class LocalFunction;

class Engine {
	public:
		Engine();
		~Engine();
		
		Variable* getVariable(unsigned int variableName);
		void setLocalFunction(unsigned int localFunctionName, LocalFunction* localFunction);
		void setGlobalFunction(unsigned int globalFunctionName, IGlobalFunction* globalFunction);
		void loadCurrentScript(Stream *stream);
		void executeCurrentScript();
		Object* executeLocalFunction(unsigned int functionName, Object** args, unsigned int argc);
		Object* executeGlobalFunction(unsigned int functionName, Object** args, unsigned int argc);
	private:
		ScriptBlock* currentScript;
		void dispose();
		
		unsigned int variablesCount;
		Variable** variables;
		
		unsigned int globalFunctionsCount;
		IGlobalFunction** globalFunctions;
		
		unsigned int localFunctionsCount;
		LocalFunction** localFunctions;
};


#endif //MHSCPP_ENGINE_H
