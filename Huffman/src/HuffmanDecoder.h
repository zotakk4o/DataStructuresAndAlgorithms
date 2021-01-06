#ifndef HUFFMANDECODER_H
#define HUFFMANDECODER_H

#include "include/String.h"

/// <summary>
/// A class responsible for DECODING a corresponding Huffman's code
/// </summary>
class HuffmanDecoder
{
	private:
		static String getBinaryCodeFromFile(const String&);
	public:
		/// <summary>
		/// Decode a given BINARY string
		/// </summary>
		/// <param>const String& the BINARY string to be decoded</param>
		/// <returns>String</returns>
		static String decode(const String&);

		/// <summary>
		/// Converts a given BINARY sequence to a byte-separated string
		/// </summary>
		/// <param>const String& the BINARY string to be debugged</param>
		/// <returns>String</returns>
		static String debug(const String&);
		virtual ~HuffmanDecoder() = 0;
};

#endif

