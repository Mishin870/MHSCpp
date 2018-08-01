//
// Created by Mishin870 on 28.07.2018.
//

#ifndef MHSCPP_ENGINE_H
#define MHSCPP_ENGINE_H


#include <vector>
#include "Variable.h"
#include "../stream/Stream.h"
#include "../commands/LocalFunction.h"
#include "IGlobalFunction.h"
#include "CallArgs.h"

class ScriptBlock;
class LocalFunction;

class Engine {
	public:
		Engine();
		~Engine();
		
		static const unsigned int CANT_FIND = -1;
		Variable* getVariable(unsigned int variableName);
		void setLocalFunction(unsigned int localFunctionName, LocalFunction* localFunction);
		void setGlobalFunction(unsigned int globalFunctionName, IGlobalFunction* globalFunction);
		void loadCurrentScript(Stream *stream);
		void executeCurrentScript();
		Object* executeLocalFunction(unsigned int functionName, Object** args, unsigned int argc);
		Object* executeGlobalFunction(unsigned int functionName, Object** args, unsigned int argc);
		unsigned int getGlobalFunctionNameByString(std::string name);
		unsigned int getLocalFunctionNameByString(std::string name);
		unsigned int getVariableByNameString(std::string name);
	private:
		void addToCallStack(CallArgs* args);
		void removeFromCallStack();
		
		std::vector<CallArgs*> callStack;
		unsigned int callStackPointer;
		
		ScriptBlock* currentScript;
		void dispose();
		
		unsigned int variablesCount;
		Variable** variables;
		std::string* variableNames;
		
		unsigned int globalFunctionsCount;
		IGlobalFunction** globalFunctions;
		std::string* globalFunctionNames;
		
		unsigned int localFunctionsCount;
		LocalFunction** localFunctions;
		std::string* localFunctionNames;
};


#endif //MHSCPP_ENGINE_H
