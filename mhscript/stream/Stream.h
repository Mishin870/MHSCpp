//
// Created by Mishin870 on 28.07.2018.
//

#ifndef MHSCPP_STREAM_H
#define MHSCPP_STREAM_H

/**
 * Описание потока, с которым умеет оперировать движок.
 * См. также: FileStream
 */
class Stream {
	public:
		virtual unsigned int readInt() = 0;
		virtual unsigned char readByte() = 0;
		virtual void skip(unsigned int count) = 0;
};


#endif //MHSCPP_STREAM_H
