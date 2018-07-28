//
// Created by Mishin870 on 28.07.2018.
//

#include "HelloCommand.h"
#include "../objects/ObjectInt.h"
#include "../objects/ObjectBool.h"

Object *HelloCommand::execute(Engine *engine) {
	return new ObjectBool(true);
}
