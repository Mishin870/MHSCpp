#include "mhscript/engine/Engine.h"
#include "mhscript/commands/ScriptBlock.h"
#include "mhscript/stream/Stream.h"
#include "mhscript/stream/FileStream.h"

int main() {
	/*ICommand* command = nullptr;
	//command = new HelloCommand();
	
	Object* result = command->execute(nullptr);
	result->trace();*/
	
	/*CommandType type = CT_SCRIPT_BLOCK;
	std::cout << type << std::endl;*/
	
	/*Variable* variable = new Variable(new ObjectBool(true));
	variable->trace();
	delete variable->value;
	delete variable;*/
	
	Stream* stream = new FileStream("test.script");
	Engine* engine = new Engine();
	//ICommand* script = new ScriptBlock(stream);
	ScriptBlock* script = engine->loadCurrentScript(stream);
	
	script->execute(engine);
	
	delete script;
	delete engine;
	delete stream;
	return 0;
}