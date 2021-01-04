#include "HuffmanEncoder.h"
#include "helpers/Helpers.h"
#include "include/File.h"
#include "config/Config.h"
#include "config/Errors.h"
#include <fstream>

void HuffmanEncoder::encode(const String& str, const String& outputFileName) {
	HuffmanTree tree{ str };
	String code = tree.encode(str);
	unsigned int codeLength = code.getLength();
	unsigned char padding = 0;

	while ((padding + codeLength) % 8 != 0) {
		padding++;
		code = String{ "0" } + code;
	}

	std::ofstream file;
	file.open(outputFileName.getConstChar(), std::ofstream::binary|std::ofstream::trunc);

	if (!file) {
		throw Errors::couldNotSaveCodeError;
	}

	file.write(reinterpret_cast<char*>(&padding), sizeof(unsigned char));

	for (unsigned int i = 0; i < padding + codeLength; i+= 8)
	{
		String symbol = code.substring(i, 8);
		unsigned char encodedChar = Helpers::BinaryStringToChar(symbol);

		file.write(reinterpret_cast<char*>(&encodedChar), sizeof(unsigned char));
	}

	file.close();

	String treeFileName = File::getFileName(outputFileName, false) + Config::treeFileNameSuffix;
	file.open(treeFileName.getConstChar(), std::ofstream::binary | std::ofstream::trunc);
	
	if (!file) {
		throw Errors::couldNotSaveTreeError;
	}

	file << tree;

	file.close();
}
