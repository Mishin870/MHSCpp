#include <iostream>
#include "mhscript/engine/Engine.h"
#include "mhscript/stream/FileStream.h"

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
	unsigned int testFunctionName = engine->getGlobalFunctionNameByString("test");
	if (testFunctionName == Engine::CANT_FIND) {
		//do something
	}
	engine->setGlobalFunction(testFunctionName, new TestFunction());
	
	
	engine->executeCurrentScript();
	
	delete engine;
	delete stream;
	return 0;
}