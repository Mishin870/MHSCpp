//
// Created by Mishin870 on 28.07.2018.
//

#ifndef MHSCPP_OBJECT_H
#define MHSCPP_OBJECT_H


#include "ObjectType.h"

/**
 * Корневой объект для всех переменных и значений в движке.
 * Служит для обобщения возвращаемых типов операторов и всего прочего.
 */
class Object {
	public:
		virtual ObjectType getType() = 0;
		virtual void trace() = 0;
};


#endif //MHSCPP_OBJECT_H
