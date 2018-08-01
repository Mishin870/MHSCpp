//
// Created by Mishin870 on 29.07.2018.
//

#include <cstdio>
#include <stdexcept>
#include "FileStream.h"

FileStream::FileStream(const char *fileName) {
	this->file = fopen(fileName, "rb");
	if (!this->file) {
		fclose(this->file);
		throw std::runtime_error("Can't open stream to file!");
	}
}

FileStream::~FileStream() {
	fclose(this->file);
}

unsigned int FileStream::readInt() {
	unsigned char buffer[4];
	fread(buffer, 1, 4, this->file);
	return (buffer[0] << 24) | (buffer[1] << 16) | (buffer[2] << 8) | buffer[3];
}

unsigned char FileStream::readByte() {
	unsigned char buffer[1];
	fread(buffer, 1, 1, this->file);
	return buffer[0];
}

void FileStream::skip(unsigned int count) {
	fseek(this->file, (long) count, SEEK_CUR);
}

void FileStream::readString(std::string& to) {
	fread(&(to[0]), 1, to.length(), this->file);
}

