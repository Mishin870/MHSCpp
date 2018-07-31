//
// Created by Mishin870 on 31.07.2018.
//

#ifndef MHSCPP_CMDMATH_H
#define MHSCPP_CMDMATH_H


#include "../../stream/Stream.h"
#include "../../engine/Engine.h"
#include "../../objects/Object.h"
#include "../ComamndType.h"
#include "../ICommand.h"
#include "../LexemKind.h"

class CmdMath : public ICommand {
	public:
		explicit CmdMath(Stream* stream);
		~CmdMath();
		
		Object* execute(Engine* engine) override;
		CommandType getType() override;
	private:
		unsigned int blocksCount;
		ICommand** blocks;
		LexemKind operation;
};


#endif //MHSCPP_CMDMATH_H
