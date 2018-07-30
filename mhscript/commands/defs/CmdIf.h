//
// Created by Mishin870 on 31.07.2018.
//

#ifndef MHSCPP_CMDIF_H
#define MHSCPP_CMDIF_H


#include "../../stream/Stream.h"
#include "../../engine/Engine.h"
#include "../../objects/Object.h"
#include "../ComamndType.h"
#include "../ICommand.h"
#include "../LexemKind.h"

class CmdIf : public ICommand {
	public:
		explicit CmdIf(Stream* stream);
		~CmdIf();
		
		Object* execute(Engine* engine) override;
		CommandType getType() override;
	private:
		ICommand* condition;
		ICommand* command;
		ICommand** elseStatements;
		unsigned int elseStatementsCount;
};


#endif //MHSCPP_CMDIF_H
