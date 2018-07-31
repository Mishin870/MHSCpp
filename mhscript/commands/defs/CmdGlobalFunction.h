//
// Created by Mishin870 on 31.07.2018.
//

#ifndef MHSCPP_CMDGLOBALFUNCTION_H
#define MHSCPP_CMDGLOBALFUNCTION_H


#include "../../stream/Stream.h"
#include "../../engine/Engine.h"
#include "../../objects/Object.h"
#include "../ComamndType.h"
#include "../ICommand.h"
#include "../LexemKind.h"

class CmdGlobalFunction : public ICommand {
	public:
		explicit CmdGlobalFunction(Stream* stream);
		~CmdGlobalFunction();
		
		Object* execute(Engine* engine) override;
		CommandType getType() override;
	private:
		bool isGlobal;
		unsigned int functionName;
		
		unsigned int argsCount;
		ICommand** args;
};


#endif //MHSCPP_CMDGLOBALFUNCTION_H
