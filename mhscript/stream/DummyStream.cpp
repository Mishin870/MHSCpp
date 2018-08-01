//
// Created by Mishin870 on 29.07.2018.
//

#include "../commands/ComamndType.h"
#include "DummyStream.h"

unsigned int DummyStream::readInt() {
	return CT_SCRIPT_BLOCK;
}

unsigned char DummyStream::readByte() {
	return CT_SCRIPT_BLOCK;
}

void DummyStream::skip(unsigned int count) {}

void DummyStream::readString(std::string& to) {
	skip(to.length());
}