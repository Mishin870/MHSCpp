//
// Created by Mishin870 on 28.07.2018.
//

#ifndef MHSCPP_OBJECTBOOL_H
#define MHSCPP_OBJECTBOOL_H


#include "Object.h"
#include "ObjectType.h"

class ObjectBool : public Object {
	public:
		explicit ObjectBool(bool value);
		
		ObjectType getType() override;
		void trace() override;
		bool value;
};


#endif //MHSCPP_OBJECTBOOL_H
