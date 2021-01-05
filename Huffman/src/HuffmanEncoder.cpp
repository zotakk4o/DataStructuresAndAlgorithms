#include "HuffmanEncoder.h"
#include "helpers/Helpers.h"
#include "include/File.h"
#include "config/Config.h"
#include "config/Errors.h"
#include <fstream>
#include <iostream>

void HuffmanEncoder::encode(const String& str, const String& outputFileName) {
	HuffmanTree tree{ str };
	String code = tree.encode(str);
	unsigned int encodedBits = code.getLength();
	unsigned int codeLength = code.getLength();
	char padding = 0;

	while ((padding + codeLength) % 8 != 0) {
		padding++;
		code = String{ "0" } + code;
	}

	std::ofstream file;
	file.open(outputFileName.getConstChar(), std::ofstream::binary|std::ofstream::trunc);

	if (!file) {
		throw Errors::couldNotSaveCodeError;
	}
	std::string test;
	test += padding;
	for (unsigned int i = 0; i < padding + codeLength; i+= 8)
	{
		String symbol = code.substring(i, 8);
		test += Helpers::BinaryStringToChar(symbol);;
	}

	file << test;
	
	file.close();

	String treeFileName = File::getFileName(outputFileName, false) + Config::treeFileNameSuffix;
	file.open(treeFileName.getConstChar(), std::ofstream::binary | std::ofstream::trunc);
	
	if (!file) {
		throw Errors::couldNotSaveTreeError;
	}

	file << tree;

	file.close();

	std::cout << "Encoded bits: " << encodedBits << std::endl;
	std::cout << "Original bits: " << (str.getLength() * 8) << std::endl;
	std::cout << "Compression ratio: " << (str.getLength() == 0 ? 0 : ((double)encodedBits / (str.getLength() * 8))) << std::endl;
}
