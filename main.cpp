#include <iostream>
#include "mhscript/commands/ICommand.h"
#include "mhscript/commands/ComamndType.h"
#include "mhscript/stream/DummyStream.h"
#include "mhscript/commands/ScriptBlock.h"
#include "mhscript/stream/FileStream.h"
#include "mhscript/engine/ScriptLoader.h"

int main() {
	/*ICommand* command = nullptr;
	//command = new HelloCommand();
	
	Object* result = command->execute(nullptr);
	result->trace();*/
	
	/*CommandType type = CT_SCRIPT_BLOCK;
	std::cout << type << std::endl;*/
	
	Stream* stream = new FileStream("test.script");
	//ICommand* script = new ScriptBlock(stream);
	ScriptBlock* script = loadScript(stream);
	
	delete script;
	delete stream;
	return 0;
}