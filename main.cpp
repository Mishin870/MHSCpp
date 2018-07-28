
#include "mhscript/commands/ICommand.h"
#include "mhscript/commands/HelloCommand.h"

int main() {
	ICommand* command;
	command = new HelloCommand();
	
	Object* result = command->execute(nullptr);
	result->trace();
	
	return 0;
}