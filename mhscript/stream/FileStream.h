//
// Created by Mishin870 on 29.07.2018.
//

#ifndef MHSCPP_FILESTREAM_H
#define MHSCPP_FILESTREAM_H

#include <string>
#include <fstream>
#include "Stream.h"

class FileStream : public Stream {
	public:
		explicit FileStream(const char* fileName);
		~FileStream();
		
		unsigned int readInt() override;
		unsigned char readByte() override;
		void readString(std::string& to) override;
		void skip(unsigned int count) override;
	
	private:
		FILE *file;
};


#endif //MHSCPP_FILESTREAM_H
