//
// Created by Mishin870 on 30.07.2018.
//

#include <stdexcept>
#include "ScriptUtils.h"
#include "../objects/ObjectBool.h"
#include "../objects/ObjectInt.h"

bool getBoolOrCrash(Object* object) {
	if (object == nullptr) {
		throw std::runtime_error("ScriptUtils::getBoolOrCrash => object is null!");
	}
	ObjectType type = object->getType();
	if (type == OT_BOOL) {
		auto* objectBool = dynamic_cast<ObjectBool*>(object);
		return objectBool->value;
	} else {
		throw std::runtime_error("ScriptUtils::getBoolOrCrash => wrong type!");
	}
}

int getIntOrCrash(Object* object) {
	if (object == nullptr) {
		throw std::runtime_error("ScriptUtils::getIntOrCrash => object is null!");
	}
	ObjectType type = object->getType();
	if (type == OT_INT) {
		auto* objectInt = dynamic_cast<ObjectInt*>(object);
		return objectInt->value;
	} else {
		throw std::runtime_error("ScriptUtils::getIntOrCrash => wrong type!");
	}
}

bool getBool(Object* object) {
	if (object == nullptr) {
		throw std::runtime_error("ScriptUtils::getBool => object is null!");
	}
	ObjectType type = object->getType();
	if (type == OT_BOOL) {
		auto* objectBool = dynamic_cast<ObjectBool*>(object);
		return objectBool->value;
	} else if (type == OT_INT) {
		auto* objectInt = dynamic_cast<ObjectInt*>(object);
		return objectInt->value == 1;
	} else {
		throw std::runtime_error("ScriptUtils::getBool => wrong type!");
	}
}

int getInt(Object* object) {
	if (object == nullptr) {
		throw std::runtime_error("ScriptUtils::getInt => object is null!");
	}
	ObjectType type = object->getType();
	if (type == OT_BOOL) {
		auto* objectBool = dynamic_cast<ObjectBool*>(object);
		return objectBool->value ? 1 : 0;
	} else if (type == OT_INT) {
		auto* objectInt = dynamic_cast<ObjectInt*>(object);
		return objectInt->value;
	} else {
		throw std::runtime_error("ScriptUtils::getInt => wrong type!");
	}
}

bool executeBool(ICommand* command, Engine* engine) {
	Object* tmp = command->execute(engine);
	bool result = getBoolOrCrash(tmp);
	delete tmp;
	return result;
}

void executeVoid(ICommand* command, Engine* engine) {
	Object* tmp = command->execute(engine);
	delete tmp;
}