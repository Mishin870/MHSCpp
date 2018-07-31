//
// Created by Mishin870 on 28.07.2018.
//

#ifndef MHSCPP_ENGINE_H
#define MHSCPP_ENGINE_H


#include "Variable.h"

class Engine {
	public:
		Engine(unsigned int variablesCount);
		~Engine();
		
		Variable* getVariable(unsigned int variableName);
	private:
		unsigned int variablesCount;
		Variable** variables;
};


#endif //MHSCPP_ENGINE_H
