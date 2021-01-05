#ifndef HUFFMANDECODER_H
#define HUFFMANDECODER_H

#include "include/String.h"

/// <summary>
/// A class responsible for DECODING a corresponding Huffman's code
/// </summary>
class HuffmanDecoder
{
	public:
		/// <summary>
		/// Decode a given BINARY string
		/// </summary>
		/// <param>const String& the BINARY string to be decoded</param>
		/// <returns>String</returns>
		static String decode(const String&);
		virtual ~HuffmanDecoder() = 0;
};

#endif

