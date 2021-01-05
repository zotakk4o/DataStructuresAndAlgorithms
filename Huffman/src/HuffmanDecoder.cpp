#include "HuffmanDecoder.h"
#include "HuffmanTree.h"
#include "helpers/Helpers.h"
#include "include/File.h"
#include "config/Config.h"
#include "config/Errors.h"
#include <string>

String HuffmanDecoder::decode(const String& inputFileName) {
	std::ifstream file;
	unsigned char padding;
	std::string encodedString;
	String binaryCode;

	file.open(inputFileName.getConstChar(), std::ofstream::binary);
	file.seekg(0);

	if (!file) {
		throw Errors::couldNotReadCodeError;
	}

	file.read(reinterpret_cast<char*>(&padding), sizeof(unsigned char));

	unsigned char symbolFromFile;
	while (file.read(reinterpret_cast<char*>(&symbolFromFile), sizeof(unsigned char))) {
		encodedString += symbolFromFile;
	}

	file.close();

	unsigned int encodedStringLength = encodedString.length();
	for (unsigned int i = 0; i < encodedStringLength; i++)
	{	
		binaryCode += Helpers::CharToBinaryString(encodedString[i]);
	}

	binaryCode = binaryCode.substring(padding, binaryCode.getLength() - padding);
	String treeFileName = File::getFileName(inputFileName, false) + Config::treeFileNameSuffix;
	file.open(treeFileName.getConstChar(), std::ifstream::binary);

	if (!file) {
		throw Errors::couldNotReadTreeError;
	}

	HuffmanTree tree;

	file >> tree;
	return tree.decode(binaryCode);
}