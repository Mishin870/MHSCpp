//
// Created by Mishin870 on 29.07.2018.
//

#ifndef MHSCPP_DUMMYSTREAM_H
#define MHSCPP_DUMMYSTREAM_H

#include <string>
#include "Stream.h"

class DummyStream : public Stream {
	public:
		unsigned int readInt() override;
		unsigned char readByte() override;
		void readString(std::string& to) override;
		void skip(unsigned int count) override;
};


#endif //MHSCPP_DUMMYSTREAM_H
