#ifndef HUFFMANENCODER_H
#define HUFFMANENCODER_H

#include "include/String.h"
#include "src/HuffmanTree.h"

/// <summary>
/// A class responsible for ENCODING a corresponding Huffman's code
/// </summary>
class HuffmanEncoder
{
	public:
		/// <summary>
		/// Encode a given string
		/// </summary>
		/// <param>const String& the string to be encoded</param>
		/// <param>const String& the output file to which to save the encoded string</param>
		/// <returns></returns>
		static void encode(const String&, const String&);
		virtual ~HuffmanEncoder() = 0;
};

#endif

