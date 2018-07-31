//
// Created by Mishin870 on 28.07.2018.
//

#include <iostream>
#include "ObjectBool.h"

ObjectType ObjectBool::getType() {
	return OT_BOOL;
}

ObjectBool::ObjectBool(bool value) {
	this->value = value;
}

void ObjectBool::trace() {
	printf("[ObjectBool value=%d]", this->value);
}

ObjectBool::~ObjectBool() {}
