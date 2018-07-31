//
// Created by Mishin870 on 31.07.2018.
//

#ifndef MHSCPP_CMDBOOL_H
#define MHSCPP_CMDBOOL_H


#include "../../stream/Stream.h"
#include "../../engine/Engine.h"
#include "../../objects/Object.h"
#include "../ComamndType.h"
#include "../ICommand.h"
#include "../LexemKind.h"

class CmdBool : public ICommand {
	public:
		explicit CmdBool(Stream* stream);
		~CmdBool();
		
		Object* execute(Engine* engine) override;
		CommandType getType() override;
	private:
		bool value;
};


#endif //MHSCPP_CMDBOOL_H
