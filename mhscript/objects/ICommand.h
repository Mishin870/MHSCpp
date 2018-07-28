//
// Created by Mishin870 on 28.07.2018.
//

#ifndef MHSCPP_ICOMMAND_H
#define MHSCPP_ICOMMAND_H


#include "../entities/Object.h"
#include "../engine/Engine.h"

class ICommand {
	public:
		virtual Object execute(Engine* engine) = 0;
};


#endif //MHSCPP_ICOMMAND_H
