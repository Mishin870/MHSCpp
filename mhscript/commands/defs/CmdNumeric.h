//
// Created by Mishin870 on 31.07.2018.
//

#ifndef MHSCPP_CMDNUMERIC_H
#define MHSCPP_CMDNUMERIC_H


#include "../../stream/Stream.h"
#include "../../engine/Engine.h"
#include "../../objects/Object.h"
#include "../ComamndType.h"
#include "../ICommand.h"
#include "../LexemKind.h"

class CmdNumeric : public ICommand {
	public:
		explicit CmdNumeric(Stream* stream);
		~CmdNumeric();
		
		Object* execute(Engine* engine) override;
		CommandType getType() override;
	private:
		int value;
};


#endif //MHSCPP_CMDNUMERIC_H
