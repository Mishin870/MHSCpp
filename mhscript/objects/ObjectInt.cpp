//
// Created by Mishin870 on 28.07.2018.
//

#include <iostream>
#include "ObjectInt.h"

ObjectType ObjectInt::getType() {
	return OT_INT;
}

ObjectInt::ObjectInt(int value) {
	this->value = value;
}

void ObjectInt::trace() {
	printf("[ObjectInt value=%d]", this->value);
}

ObjectInt::~ObjectInt() {}
