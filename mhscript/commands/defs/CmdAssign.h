//
// Created by Mishin870 on 31.07.2018.
//

#ifndef MHSCPP_CMDASSIGN_H
#define MHSCPP_CMDASSIGN_H


#include "../../stream/Stream.h"
#include "../../engine/Engine.h"
#include "../../objects/Object.h"
#include "../ComamndType.h"
#include "../ICommand.h"
#include "../LexemKind.h"

class CmdAssign : public ICommand {
	public:
		explicit CmdAssign(Stream* stream);
		~CmdAssign();
		
		Object* execute(Engine* engine) override;
		CommandType getType() override;
	private:
		ICommand* left;
		ICommand* right;
};


#endif //MHSCPP_CMDASSIGN_H
