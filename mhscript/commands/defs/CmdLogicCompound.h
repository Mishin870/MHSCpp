//
// Created by Mishin870 on 30.07.2018.
//

#ifndef MHSCPP_CMDLOGICCOMPOUND_H
#define MHSCPP_CMDLOGICCOMPOUND_H


#include "../../stream/Stream.h"
#include "../../engine/Engine.h"
#include "../../objects/Object.h"
#include "../ComamndType.h"
#include "../ICommand.h"
#include "../LexemKind.h"

class CmdLogicCompound : public ICommand {
	public:
		CmdLogicCompound(Stream* stream);
		~CmdLogicCompound();
		
		Object* execute(Engine* engine) override;
		CommandType getType() override;
	private:
		unsigned int blocksCount;
		ICommand** blocks;
		LexemKind operation;
};


#endif //MHSCPP_CMDLOGICCOMPOUND_H
