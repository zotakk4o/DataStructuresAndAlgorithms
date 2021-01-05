#include "CompressCommand.h"
#include "src/HuffmanEncoder.h"
#include "include/File.h"
#include "src/helpers/Helpers.h"
#include<iostream>
#include <string>
#include <fstream>
#include <streambuf>


void CompressCommand::execute(Vector<String*>& filesNames) const {
	File input{*filesNames[0], true};
	HuffmanEncoder::encode(input.getData(), *filesNames[1]);
	Helpers::exitProgram();
}

String CompressCommand::toString() const {
	return "c";
}

