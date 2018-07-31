//
// Created by Mishin870 on 28.07.2018.
//

#include <stdexcept>
#include <iostream>
#include "ScriptLoader.h"
#include "../commands/defs/CmdAssign.h"
#include "../commands/defs/CmdBool.h"
#include "../commands/defs/CmdElse.h"
#include "../commands/defs/CmdElseIf.h"
#include "../commands/defs/CmdEmpty.h"
#include "../commands/defs/CmdFor.h"
#include "../commands/defs/CmdIf.h"
#include "../commands/defs/CmdLogic.h"
#include "../commands/defs/CmdLogicCompound.h"
#include "../commands/defs/CmdMath.h"
#include "../commands/defs/CmdNumeric.h"
#include "../commands/defs/CmdReturn.h"
#include "../commands/defs/CmdUnary.h"
#include "../commands/defs/CmdVariable.h"
#include "../commands/defs/CmdWhile.h"

ICommand* loadCommand(Stream* stream) {
	CommandType type = static_cast<CommandType>(stream->readByte());
	switch (type) {
		case CT_SCRIPT_BLOCK:
			return new ScriptBlock(stream);
		case CT_ASSIGN:
			return new CmdAssign(stream);
		case CT_BOOL:
			return new CmdBool(stream);
		case CT_ELSE:
			return new CmdElse(stream);
		case CT_ELSE_IF:
			return new CmdElseIf(stream);
		case CT_EMPTY:
			return new CmdEmpty(stream);
		case CT_FOR:
			return new CmdFor(stream);
		case CT_IF:
			return new CmdIf(stream);
		case CT_LOGIC:
			return new CmdLogic(stream);
		case CT_LOGIC_COMPOUND:
			return new CmdLogicCompound(stream);
		case CT_MATH:
			return new CmdMath(stream);
		case CT_NUMERIC:
			return new CmdNumeric(stream);
		case CT_RETURN:
			return new CmdReturn(stream);
		case CT_UNARY:
			return new CmdUnary(stream);
		case CT_VARIABLE:
			return new CmdVariable(stream);
		case CT_WHILE:
			return new CmdWhile(stream);
		default:
			throw std::runtime_error("Not supported command type in ScriptLoader::loadCommand!");
	}
}

ICommand** loadBlock(Stream* stream, unsigned int &count) {
	unsigned int blocksCount = stream->readInt();
	count = blocksCount;
	ICommand** blocks = new ICommand*[blocksCount];
	unsigned int i;
	for (i = 0; i < blocksCount; i++) {
		blocks[i] = loadCommand(stream);
	}
	return blocks;
}