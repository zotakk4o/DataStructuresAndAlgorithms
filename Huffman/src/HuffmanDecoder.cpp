#include "HuffmanDecoder.h"
#include "HuffmanTree.h"
#include "helpers/Helpers.h"
#include "include/File.h"
#include "config/Config.h"
#include "config/Errors.h"

String HuffmanDecoder::decode(const String& inputFileName) {
	std::ifstream file;
	unsigned char padding;
	String encodedString;
	String binaryCode;

	file.open(inputFileName.getConstChar(), std::ofstream::binary);

	if (!file) {
		throw Errors::couldNotReadCodeError;
	}

	file.read(reinterpret_cast<char*>(&padding), sizeof(unsigned char));

	unsigned char symbolFromFile;
	while (file.read(reinterpret_cast<char*>(&symbolFromFile), sizeof(unsigned char))) {
		encodedString += symbolFromFile;
	}

	file.close();

	unsigned int encodedStringLength = encodedString.getLength();
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