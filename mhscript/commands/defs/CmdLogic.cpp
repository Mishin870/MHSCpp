//
// Created by Mishin870 on 30.07.2018.
//

#include <stdexcept>
#include "CmdLogic.h"
#include "../../engine/ScriptLoader.h"
#include "../ScriptUtils.h"
#include "../../objects/ObjectBool.h"

CmdLogic::CmdLogic(Stream *stream) {
	this->operation = static_cast<LexemKind>(stream->readByte());
	this->left = loadCommand(stream);
	this->right = loadCommand(stream);
}

CmdLogic::~CmdLogic() {
	delete this->left;
	delete this->right;
}

Object *CmdLogic::execute(Engine *engine) {
	Object* object1 = left->execute(engine);
	Object* object2 = right->execute(engine);
	ObjectType type1 = object1->getType();
	ObjectType type2 = object2->getType();
	
	switch (this->operation) {
		case EQUALS:
			if (type1 == type2) {
				switch (type1) {
					case OT_BOOL:
						return new ObjectBool(getBoolOrCrash(object1) == getBoolOrCrash(object2));
					case OT_INT:
						return new ObjectBool(getIntOrCrash(object1) == getIntOrCrash(object2));
				}
			} else {
				return new ObjectBool(false);
			}
			break;
		case NOTEQUALS:
			if (type1 == type2) {
				switch (type1) {
					case OT_BOOL:
						return new ObjectBool(getBoolOrCrash(object1) != getBoolOrCrash(object2));
					case OT_INT:
						return new ObjectBool(getIntOrCrash(object1) != getIntOrCrash(object2));
				}
			} else {
				return new ObjectBool(true);
			}
			break;
		default:
			break;
	}
	if (type1 == OT_INT && type2 == OT_INT) {
		int x1 = getIntOrCrash(object1);
		int x2 = getIntOrCrash(object2);
		switch (this->operation) {
			case LESSER:
				return new ObjectBool(x1 < x2);
			case GREATER:
				return new ObjectBool(x1 > x2);
			case LESSER_EQUALS:
				return new ObjectBool(x1 <= x2);
			case GREATER_EQUALS:
				return new ObjectBool(x1 >= x2);
			default:
				throw std::runtime_error("CmdLogic::execute => unknown operation!");
		}
	} else {
		throw std::runtime_error("CmdLogic::execute => can't compare different types!");
	}
}

CommandType CmdLogic::getType() {
	return CT_LOGIC;
}
