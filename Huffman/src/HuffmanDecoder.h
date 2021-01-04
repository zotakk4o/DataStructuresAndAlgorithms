#ifndef HUFFMANDECODER_H
#define HUFFMANDECODER_H

#include "include/String.h"

class HuffmanDecoder
{
	public:
		static String decode(const String&);
		virtual ~HuffmanDecoder() = 0;
};

#endif

