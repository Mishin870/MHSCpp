//
// Created by Mishin870 on 30.07.2018.
//

#ifndef MHSCPP_COMMANDRETURN_H
#define MHSCPP_COMMANDRETURN_H


#include "../../stream/Stream.h"
#include "../../engine/Engine.h"
#include "../../objects/Object.h"
#include "../ComamndType.h"
#include "../ICommand.h"
#include "../LexemKind.h"

class CmdReturn : public ICommand {
	public:
		explicit CmdReturn(Stream* stream);
		~CmdReturn();
		
		Object* execute(Engine* engine) override;
		CommandType getType() override;
	private:
		ICommand* command;
};


#endif //MHSCPP_COMMANDRETURN_H
