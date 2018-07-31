//
// Created by Mishin870 on 31.07.2018.
//

#include <iostream>
#include "Variable.h"

ObjectType Variable::getType() {
	return OT_VARIABLE;
}

Variable::Variable(Object* value) {
	this->value = value;
}

void Variable::dump(std::ostringstream &stream) {
	stream << "Variable[";
	this->value->dump(stream);
	stream << "]";
}

Variable::~Variable() {
	delete this->value;
}
