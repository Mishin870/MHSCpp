cmake_minimum_required(VERSION 3.9)
project(MHSCpp)

set(CMAKE_CXX_STANDARD 11)

add_executable(MHSCpp
		main.cpp
		mhscript/commands/ICommand.h
		mhscript/objects/Object.h
		mhscript/objects/ObjectType.h mhscript/objects/ObjectInt.cpp mhscript/objects/ObjectInt.h mhscript/engine/Engine.cpp mhscript/engine/Engine.h mhscript/commands/HelloCommand.cpp mhscript/commands/HelloCommand.h mhscript/objects/ObjectBool.cpp mhscript/objects/ObjectBool.h)