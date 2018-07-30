//
// Created by Mishin870 on 31.07.2018.
//

#ifndef MHSCPP_CMDELSEIF_H
#define MHSCPP_CMDELSEIF_H


#include "../../stream/Stream.h"
#include "../../engine/Engine.h"
#include "../../objects/Object.h"
#include "../ComamndType.h"
#include "../ICommand.h"
#include "../LexemKind.h"

class CmdElseIf : public ICommand {
	public:
		explicit CmdElseIf(Stream* stream);
		~CmdElseIf();
		
		Object* execute(Engine* engine) override;
		CommandType getType() override;
	private:
		ICommand* command;
		ICommand* condition;
};


#endif //MHSCPP_CMDELSEIF_H
