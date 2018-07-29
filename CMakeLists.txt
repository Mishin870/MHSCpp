cmake_minimum_required(VERSION 3.9)
project(MHSCpp)

set(CMAKE_CXX_STANDARD 11)

add_executable(MHSCpp
		main.cpp
		mhscript/commands/ICommand.h
		mhscript/objects/Object.h
		mhscript/objects/ObjectType.h
		mhscript/objects/ObjectInt.cpp
		mhscript/objects/ObjectInt.h
		mhscript/engine/Engine.cpp
		mhscript/engine/Engine.h
		mhscript/objects/ObjectBool.cpp
		mhscript/objects/ObjectBool.h
		mhscript/engine/ScriptLoader.cpp
		mhscript/engine/ScriptLoader.h
		mhscript/commands/ScriptBlock.cpp
		mhscript/commands/ScriptBlock.h
		mhscript/commands/LocalFunction.cpp
		mhscript/commands/LocalFunction.h
		mhscript/stream/Stream.h
		mhscript/commands/ComamndType.h mhscript/stream/DummyStream.cpp mhscript/stream/DummyStream.h mhscript/stream/FileStream.cpp mhscript/stream/FileStream.h mhscript/commands/defs/CmdLogicCompound.cpp mhscript/commands/defs/CmdLogicCompound.h mhscript/commands/LexemKind.h mhscript/commands/ScriptUtils.cpp mhscript/commands/ScriptUtils.h)