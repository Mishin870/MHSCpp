//
// Created by Mishin870 on 30.07.2018.
//

#ifndef MHSCPP_CMDELSE_H
#define MHSCPP_CMDELSE_H


#include "../../stream/Stream.h"
#include "../../engine/Engine.h"
#include "../../objects/Object.h"
#include "../ComamndType.h"
#include "../ICommand.h"
#include "../LexemKind.h"

class CmdElse : public ICommand {
	public:
		explicit CmdElse(Stream* stream);
		~CmdElse();
		
		Object* execute(Engine* engine) override;
		CommandType getType() override;
	private:
		ICommand* command;
};


#endif //MHSCPP_CMDELSE_H
