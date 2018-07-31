//
// Created by Mishin870 on 31.07.2018.
//

#ifndef MHSCPP_CMDEMPTY_H
#define MHSCPP_CMDEMPTY_H


#include "../../stream/Stream.h"
#include "../../engine/Engine.h"
#include "../../objects/Object.h"
#include "../ComamndType.h"
#include "../ICommand.h"
#include "../LexemKind.h"

class CmdEmpty : public ICommand {
	public:
		explicit CmdEmpty(Stream* stream);
		~CmdEmpty();
		
		Object* execute(Engine* engine) override;
		CommandType getType() override;
};


#endif //MHSCPP_CMDEMPTY_H
