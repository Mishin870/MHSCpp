//
// Created by Mishin870 on 30.07.2018.
//

#ifndef MHSCPP_CmdLogic_H
#define MHSCPP_CmdLogic_H


#include "../../stream/Stream.h"
#include "../../engine/Engine.h"
#include "../../objects/Object.h"
#include "../ComamndType.h"
#include "../ICommand.h"
#include "../LexemKind.h"

class CmdLogic : public ICommand {
	public:
		explicit CmdLogic(Stream* stream);
		~CmdLogic();
		
		Object* execute(Engine* engine) override;
		CommandType getType() override;
	private:
		ICommand* left;
		ICommand* right;
		LexemKind operation;
};


#endif //MHSCPP_CmdLogic_H
