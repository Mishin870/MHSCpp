cmake_minimum_required(VERSION 3.9)
project(MHSCpp)

set(CMAKE_CXX_STANDARD 11)

add_executable(MHSCpp
		main.cpp
		mhscript/objects/ICommand.h
		mhscript/entities/Object.h
		mhscript/entities/ObjectType.h mhscript/entities/ObjectInt.cpp mhscript/entities/ObjectInt.h mhscript/engine/Engine.cpp mhscript/engine/Engine.h)