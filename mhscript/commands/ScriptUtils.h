//
// Created by Mishin870 on 30.07.2018.
//

#ifndef MHSCPP_SCRIPTUTILS_H
#define MHSCPP_SCRIPTUTILS_H


#include "../objects/Object.h"

bool getBoolOrCrash(Object* object);
int getIntOrCrash(Object* object);
bool getBool(Object* object);
int getInt(Object* object);


#endif //MHSCPP_SCRIPTUTILS_H
