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
		mhscript/commands/ComamndType.h
		mhscript/stream/DummyStream.cpp
		mhscript/stream/DummyStream.h
		mhscript/stream/FileStream.cpp
		mhscript/stream/FileStream.h
		mhscript/commands/defs/CmdLogicCompound.cpp
		mhscript/commands/defs/CmdLogicCompound.h
		mhscript/commands/defs/CmdLogic.cpp
		mhscript/commands/defs/CmdLogic.h
		mhscript/commands/LexemKind.h
		mhscript/commands/ScriptUtils.cpp
		mhscript/commands/ScriptUtils.h
		mhscript/commands/ScriptException.cpp
		mhscript/commands/ScriptException.h
		mhscript/commands/ScriptExceptionType.h
		mhscript/commands/defs/CmdReturn.cpp
		mhscript/commands/defs/CmdReturn.h
		mhscript/commands/defs/CmdElse.cpp
		mhscript/commands/defs/CmdElse.h
		mhscript/commands/defs/CmdElseIf.cpp
		mhscript/commands/defs/CmdElseIf.h
		mhscript/commands/defs/CmdIf.cpp
		mhscript/commands/defs/CmdIf.h
		mhscript/commands/defs/CmdFor.cpp
		mhscript/commands/defs/CmdFor.h
		mhscript/commands/defs/CmdWhile.cpp
		mhscript/commands/defs/CmdWhile.h
		mhscript/commands/defs/CmdEmpty.cpp
		mhscript/commands/defs/CmdEmpty.h
		mhscript/engine/Variable.cpp
		mhscript/engine/Variable.h mhscript/commands/defs/CmdAssign.cpp mhscript/commands/defs/CmdAssign.h mhscript/commands/defs/CmdUnary.cpp mhscript/commands/defs/CmdUnary.h)