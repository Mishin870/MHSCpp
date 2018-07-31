//
// Created by Mishin870 on 28.07.2018.
//

#include "Engine.h"

Engine::Engine(unsigned int variablesCount) {
	this->variablesCount = variablesCount;
	this->variables = new Variable*[this->variablesCount];
	unsigned int i;
	for (i = 0; i < this->variablesCount; i++) {
		this->variables[i] = new Variable(nullptr);
	}
}

Engine::~Engine() {
	unsigned int i;
	for (i = 0; i < this->variablesCount; i++) {
		delete this->variables[i];
	}
	delete[] this->variables;
}

Variable *Engine::getVariable(unsigned int variableName) {
	return this->variables[variableName];
}

