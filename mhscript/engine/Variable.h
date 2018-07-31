//
// Created by Mishin870 on 31.07.2018.
//

#ifndef MHSCPP_VARIABLE_H
#define MHSCPP_VARIABLE_H


#include "../objects/Object.h"

/**
 * Объект-переменная, которая хранит в себе другой объект.
 * Служит лишь для того, чтобы изменять чужую ссылку на объект удалённо,
 * а также менять тип объекта (например, ObjectInt => ObjectBool).
 */
class Variable : public Object {
	public:
		explicit Variable(Object* value);
		~Variable();
		
		ObjectType getType() override;
		void trace() override;
		Object* value;
};


#endif //MHSCPP_VARIABLE_H
