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

void ObjectInt::dump(std::ostringstream &stream) {
	stream << "Int(" << this->value << ")";
}

ObjectInt::~ObjectInt() {}
