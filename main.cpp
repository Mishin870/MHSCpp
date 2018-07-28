#include <iostream>
#include "mhscript/objects/ICommand.h"
#include "mhscript/entities/Object.h"
#include "mhscript/entities/ObjectInt.h"

int main() {
	Object* object = new ObjectInt();
	printf("%d\n", object->getType());
	
	return 0;
}