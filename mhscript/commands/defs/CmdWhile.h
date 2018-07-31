//
// Created by Mishin870 on 31.07.2018.
//

#ifndef MHSCPP_CMDWHILE_H
#define MHSCPP_CMDWHILE_H

#include "../../stream/Stream.h"
#include "../../engine/Engine.h"
#include "../../objects/Object.h"
#include "../ComamndType.h"
#include "../ICommand.h"
#include "../LexemKind.h"

class CmdWhile : public ICommand {
	public:
		explicit CmdWhile(Stream* stream);
		~CmdWhile();
		
		Object* execute(Engine* engine) override;
		CommandType getType() override;
	private:
		ICommand* condition;
		ICommand* command;
};


#endif //MHSCPP_CMDWHILE_H
