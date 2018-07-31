//
// Created by Mishin870 on 28.07.2018.
//

#ifndef MHSCPP_SCRIPTLOADER_H
#define MHSCPP_SCRIPTLOADER_H


#include "../stream/Stream.h"
#include "../commands/ICommand.h"
#include "../commands/ScriptBlock.h"

ICommand* loadCommand(Stream* stream);
ICommand** loadBlock(Stream* stream, unsigned int &count);

#endif //MHSCPP_SCRIPTLOADER_H
