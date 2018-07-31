//
// Created by Mishin870 on 30.07.2018.
//

#ifndef MHSCPP_SCRIPTUTILS_H
#define MHSCPP_SCRIPTUTILS_H


#include "../objects/Object.h"
#include "ICommand.h"
#include "../engine/Variable.h"

Variable* getVariableOrCrash(Object* object);
bool getBoolOrCrash(Object* object);
int getIntOrCrash(Object* object);
bool getBool(Object* object);
int getInt(Object* object);

bool executeBool(ICommand* command, Engine* engine);
int executeInt(ICommand* command, Engine* engine);
void executeVoid(ICommand* command, Engine* engine);
Variable* executeVariable(ICommand* command, Engine* engine);

void setIntVariable(Variable* variable, int value);
void setBoolVariable(Variable* variable, bool value);


#endif //MHSCPP_SCRIPTUTILS_H
