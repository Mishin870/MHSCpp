//
// Created by Mishin870 on 31.07.2018.
//

#ifndef MHSCPP_CMDFOR_H
#define MHSCPP_CMDFOR_H


#include "../../stream/Stream.h"
#include "../../engine/Engine.h"
#include "../../objects/Object.h"
#include "../ComamndType.h"
#include "../ICommand.h"
#include "../LexemKind.h"

class CmdFor : public ICommand {
	public:
		explicit CmdFor(Stream* stream);
		~CmdFor();
		
		Object* execute(Engine* engine) override;
		CommandType getType() override;
	private:
		ICommand* condition;
		ICommand* pre;
		ICommand* iter;
		ICommand* command;
};


#endif //MHSCPP_CMDFOR_H
