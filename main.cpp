#include <iostream>
#include "mhscript/engine/Engine.h"
#include "mhscript/stream/FileStream.h"
#include "mhscript/objects/ObjectInt.h"

class TestFunction : public IGlobalFunction {
	public:
		Object* execute(Object** args, unsigned int argc) override {
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
	Stream* stream = new FileStream("test.script");
	Engine* engine = new Engine();
	
	engine->loadCurrentScript(stream);
	delete stream;
	
	unsigned int testFunctionName = engine->getGlobalFunctionNameByString("test");
	if (testFunctionName == Engine::CANT_FIND) {
		//do something
	}
	engine->setGlobalFunction(testFunctionName, new TestFunction());
	
	engine->executeCurrentScript();
	unsigned int myTestFunctionName = engine->getLocalFunctionNameByString("myTestFunction");
	
	unsigned int argc = 1;
	Object** args = new Object*[argc];
	args[0] = new ObjectInt(100500);
	engine->executeLocalFunction(myTestFunctionName, args, argc);
	
	delete engine;
	return 0;
}