//
// Created by Mishin870 on 28.07.2018.
//

#ifndef MHSCPP_SCRIPTBLOCK_H
#define MHSCPP_SCRIPTBLOCK_H


#include "ICommand.h"
#include "LocalFunction.h"

class LocalFunction;
class Stream;

class ScriptBlock : public ICommand {
	public:
		explicit ScriptBlock(Stream* stream);
		~ScriptBlock();
		
		CommandType getType() override;
		Object* execute(Engine* engine) override;
	private:
		bool isRoot;
		
		unsigned int commandsCount;
		ICommand** commands;
		
		unsigned int functionsCount;
		LocalFunction** functions;
};


#endif //MHSCPP_SCRIPTBLOCK_H
