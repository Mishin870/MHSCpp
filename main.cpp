#include <iostream>
#include "mhscript/engine/Engine.h"
#include "mhscript/commands/ScriptBlock.h"
#include "mhscript/stream/Stream.h"
#include "mhscript/stream/FileStream.h"

class TestFunction : public IGlobalFunction {
	public:
		Object* execute(Object** args, unsigned int argc) {
			unsigned int i;
			std::ostringstream stream;
			for (i = 0; i < argc; i++) {
				args[i]->dump(stream);
				std::cout << stream.str() << " ";
				stream.clear();
			}
			std::cout << std::endl;
		}
};

int main() {
	/*ICommand* command = nullptr;
	//command = new HelloCommand();
	
	Object* result = command->execute(nullptr);
	result->dump();*/
	
	/*CommandType type = CT_SCRIPT_BLOCK;
	std::cout << type << std::endl;*/
	
	/*Variable* variable = new Variable(new ObjectBool(true));
	variable->dump();
	delete variable->value;
	delete variable;*/
	
	Stream* stream = new FileStream("test.script");
	Engine* engine = new Engine();
	//ICommand* script = new ScriptBlock(stream);
	engine->loadCurrentScript(stream);
	engine->setGlobalFunction(0, new TestFunction());
	
	
	engine->executeCurrentScript();
	
	delete engine;
	delete stream;
	return 0;
}