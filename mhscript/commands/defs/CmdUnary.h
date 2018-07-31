//
// Created by Mishin870 on 31.07.2018.
//

#ifndef MHSCPP_CMDUNARY_H
#define MHSCPP_CMDUNARY_H


#include "../../stream/Stream.h"
#include "../../engine/Engine.h"
#include "../../objects/Object.h"
#include "../ComamndType.h"
#include "../ICommand.h"
#include "../LexemKind.h"

class CmdUnary : public ICommand {
	public:
		explicit CmdUnary(Stream* stream);
		~CmdUnary();
		
		Object* execute(Engine* engine) override;
		CommandType getType() override;
	private:
		ICommand* command;
		LexemKind operation;
};


#endif //MHSCPP_CMDUNARY_H
