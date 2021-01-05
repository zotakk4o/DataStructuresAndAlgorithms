#include<iostream>
#include<new>
#include<string>
#include "File.h"
#include <iterator>
#include <algorithm>

File::~File() {};

File::File(const String& _path, bool openOnCreation) : data(""), path(_path), opened(false) {
	if (openOnCreation && _path.getLength()) {
		this->open(_path);
	}
};

bool File::open(const String& fileName) {
	if (this->opened) {
		return false;
	}

	std::fstream fs;
	fs.open(fileName.getConstChar(), std::fstream::in);
	fs.seekg(0, fs.beg);

	if (!fs.is_open()) {
		fs.open(fileName.getConstChar(), std::fstream::out);

		if (fs.is_open()) {
			fs.close();
			this->path = fileName;
			this->opened = true;
			return true;
		}

		throw String{ "\"" } +fileName + "\" could not be opened due to an error.";
		return false;
	}

	std::string content((std::istreambuf_iterator<char>(fs)), (std::istreambuf_iterator<char>()));
	this->data = content.c_str();

	fs.close();
	this->opened = true;
	this->path = fileName;

	return true;
}


bool File::save() {
	return this->saveData(this->path);
}

bool File::saveAs(const String& filename) {
	return this->saveData(filename);
}

bool File::saveData(const String& filename) {
	if (!this->opened) {
		throw String{ "Could not save \"" } +filename + "\". The file has not been opened for processing.";
		return false;
	}

	std::fstream fs;
	fs.open(filename.getConstChar(), std::fstream::out | std::fstream::trunc);

	if (!fs.is_open()) {
		throw String{ "Data could not be saved in \"" } + filename + "\".";
		fs.close();
		return false;
	}

	fs.write(this->data.getConstChar(), this->data.getLength());
	if (!fs.good()) {
		fs.close();
		return false;
	}

	fs.close();
	
	return true;
}

bool File::close() {
	if (!this->opened) {
		throw "No file has been opened for processing.";
		return false;
	}

	this->data = "";
	this->path = "";
	this->opened = false;

	return true;
}

String File::getFileName(const String& path, bool withExtension) {
	char dirSeparator = '/';

	#ifdef _WIN32
		dirSeparator = '\\';
	#endif

	String reversedPath = path.reverse();

	unsigned short lastSeparatorIndex = path.getLength() - reversedPath.indexOf(dirSeparator);
	unsigned short extensionIndex = path.getLength() - reversedPath.indexOf('.') - 1;

	if (lastSeparatorIndex > path.getLength()) {
		lastSeparatorIndex = 0;
	}

	if (!withExtension) {
		return path.substring(lastSeparatorIndex, extensionIndex - lastSeparatorIndex);
	}

	return path.substring(lastSeparatorIndex, path.getLength() - lastSeparatorIndex);
}

void File::setData(const String& newData) {
	this->data = newData;
}

void File::setPath(const String& newPath) {
	this->path = newPath;
}

String File::getData() const {
	return this->data;
}

String File::getPath() const {
	return this->path;
}

bool File::isOpened() const {
	return this->opened;
}