//
// Created by Mishin870 on 31.07.2018.
//

#ifndef MHSCPP_VARIABLE_H
#define MHSCPP_VARIABLE_H


#include "../objects/Object.h"

class Variable : public Object {
	public:
		explicit Variable(Object* value);
		
		ObjectType getType() override;
		void trace() override;
		Object* value;
};


#endif //MHSCPP_VARIABLE_H
