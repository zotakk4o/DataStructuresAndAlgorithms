#ifndef HUFFMANENCODER_H
#define HUFFMANENCODER_H

#include "include/String.h"
#include "src/HuffmanTree.h"

class HuffmanEncoder
{
	public:
		static void encode(const String&, const String&);
		virtual ~HuffmanEncoder() = 0;
};

#endif

