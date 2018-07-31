//
// Created by Mishin870 on 28.07.2018.
//

#ifndef MHSCPP_OBJECTINT_H
#define MHSCPP_OBJECTINT_H


#include "Object.h"

class ObjectInt : public Object {
	public:
		explicit ObjectInt(int value);
		~ObjectInt();
		
		ObjectType getType() override;
		void trace() override;
		int value;
};


#endif //MHSCPP_OBJECTINT_H
