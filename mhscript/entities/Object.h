//
// Created by Mishin870 on 28.07.2018.
//

#ifndef MHSCPP_OBJECT_H
#define MHSCPP_OBJECT_H


#include "ObjectType.h"

class Object {
	public:
		virtual ObjectType getType() = 0;
};


#endif //MHSCPP_OBJECT_H
