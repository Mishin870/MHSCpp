//
// Created by Mishin870 on 28.07.2018.
//

#ifndef MHSCPP_HELLOCOMMAND_H
#define MHSCPP_HELLOCOMMAND_H


#include "ICommand.h"
#include "../engine/Engine.h"

class HelloCommand : public ICommand {
	public:
		Object* execute(Engine* engine);
};


#endif //MHSCPP_HELLOCOMMAND_H
