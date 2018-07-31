//
// Created by Mishin870 on 31.07.2018.
//

#ifndef MHSCPP_CMDVARIABLE_H
#define MHSCPP_CMDVARIABLE_H


#include "../../stream/Stream.h"
#include "../../engine/Engine.h"
#include "../../objects/Object.h"
#include "../ComamndType.h"
#include "../ICommand.h"
#include "../LexemKind.h"

class CmdVariable : public ICommand {
	public:
		explicit CmdVariable(Stream* stream);
		~CmdVariable();
		
		Object* execute(Engine* engine) override;
		CommandType getType() override;
	private:
		unsigned int variableName;
};


#endif //MHSCPP_CMDVARIABLE_H
