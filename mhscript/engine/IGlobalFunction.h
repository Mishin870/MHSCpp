//
// Created by Mishin870 on 31.07.2018.
//

#ifndef MHSCPP_IGLOBALFUNCTION_H
#define MHSCPP_IGLOBALFUNCTION_H


#include "../objects/Object.h"

class IGlobalFunction {
	public:
		virtual Object* execute(Object** args, unsigned int argc) = 0;
};


#endif //MHSCPP_IGLOBALFUNCTION_H
