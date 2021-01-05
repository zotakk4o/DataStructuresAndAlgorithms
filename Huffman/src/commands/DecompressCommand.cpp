#include "DecompressCommand.h"
#include "src/HuffmanDecoder.h"
#include "src/helpers/Helpers.h"
#include "include/File.h"

void DecompressCommand::execute(Vector<String*>& filesNames) const {
	File outputFile{ *filesNames[1], true };
	outputFile.setData(HuffmanDecoder::decode(*filesNames[0]));
	outputFile.save();
	Helpers::exitProgram();
}

String DecompressCommand::toString() const {
	return "d";
}