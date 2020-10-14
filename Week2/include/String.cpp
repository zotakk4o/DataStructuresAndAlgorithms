#ifndef STRING_CPP
#define STRING_CPP
#include<new>
#include<assert.h>
#include "String.h"
#include<istream>
#include <stdexcept>

String numToString(unsigned long long num) {
	String res;

	unsigned short digits = 1;
	unsigned long long decimals = 1;

	while (decimals * 10 <= num) {
		digits++;
		decimals *= 10;
	}

	while (digits != 0) {
		res += ((num / decimals) + '0');
		num %= decimals;
		decimals /= 10;
		digits--;
	}

	return res;
}

unsigned int strLen(const char* str) {
	unsigned int res = 0;
	for (unsigned int i = 0; str[i]; i++)
	{
		res++;
	}

	return res;
}

unsigned int max(const int& first, const int& second) {
	return first >= second ? first : second;
}

unsigned int min(const int& first, const int& second) {
	return first >= second ? second : first;
}

short strCompare(const char* first, const char* second) {
	unsigned int firstLength = strLen(first);
	unsigned int secondLength = strLen(second);

	unsigned int minLength = min(firstLength, secondLength);
	for (unsigned int i = 0; i < minLength; i++)
	{
		if (first[i] < second[i]) {
			return -1;
		}
		else if (first[i] > second[i]) {
			return 1;
		}
	}

	if (firstLength == secondLength) {
		return 0;
	}

	return firstLength > secondLength ? 1 : -1;
}

void strCopy(const char* source, char* destination) {
	if (source == nullptr || destination == nullptr) {
		return;
	}

	unsigned int sourceLength = strLen(source);
	unsigned int destinationLength = strLen(destination);
	
	assert(destinationLength >= sourceLength);

	for (unsigned int i = 0; i < sourceLength; i++)
	{
		destination[i] = source[i];
	}

	destination[sourceLength] = '\0';
}

void strConcat(char* destination, const char* source) {
	unsigned int sourceLength = strLen(source);
	unsigned int destinationLength = strLen(destination);
	unsigned int sourceIndex = 0;

	for (unsigned int i = destinationLength; i < destinationLength + sourceLength; i++)
	{
		destination[i] = source[sourceIndex];
		sourceIndex++;
	}

	destination[destinationLength + sourceLength] = '\0';
}

const unsigned short String::defaultCapacity = 50; //This capacity will be doubled

String::String(const char& character) : capacity(0), length(1), str(nullptr) {
	this->reserve();
	this->str[0] = character;
	this->str[1] = '\0';
}

String::String(const char* _str) : capacity(0), length(0), str(nullptr) {
	assert(_str != nullptr);

	this->length = strlen(_str);
	this->reserve(this->length);

	strCopy(_str, this->str);
}

String::String(const String& other) : capacity(0), length(0), str(nullptr) {
	if (this != &other) {
		this->copy(other);
	}
}

String::~String() {
	this->deleteInternals();
}

String& String::operator=(const String& other) {
	if (this != &other) {
		this->copy(other);
	}

	return *this;
}

String& String::operator+=(const String& other) {
	this->copy(*this + other);

	return *this;
}
String& String::operator+=(const char* str) {
	this->copy(*this + str);

	return *this;
}

String& String::operator+=(const char& character) {
	this->copy(*this + character);

	return *this;
}

String String::operator+(const String& other) const {
	String result = *this;

	if (other.length + result.length >= result.capacity) {
		result.reserve(max(other.length, result.length));
	}

	strConcat(result.str, other.str);
	result.length += other.length;

	return result;
}
String String::operator+(const char* str) const {
	String result = *this;
	unsigned int strLength = strLen(str);

	if (strLength + result.length >= result.capacity) {
		result.reserve(max(strLength, result.length));
	}

	strConcat(result.str, str);
	result.length += strLength;

	return result;
}
String String::operator+(const char& character) const {
	String result = *this;

	if (result.length + 1 >= result.capacity) {
		result.reserve(result.length);
	}

	result.str[result.length++] = character;
	result.str[result.length] = '\0';

	return result;
}

bool String::operator==(const String& other) const {
	return strCompare(this->str, other.str) == 0;
}
bool String::operator==(const char* str) const {
	return strCompare(this->str, str) == 0;
}

bool String::operator!=(const char* str) const {
	return !(*this == str);
}

bool String::operator!=(const String& other) const {
	return !(*this == other);
}

bool String::operator>(const String& other) const {
	return strCompare(this->str, other.str) == 1;
}
bool String::operator>(const char* str) const {
	return strCompare(this->str, str) == 1;
}

bool String::operator<(const String& other) const {
	return strCompare(this->str, other.str) == -1;
}

bool String::operator<(const char* str) const {
	return strCompare(this->str, str) == -1;
}

bool String::operator>=(const char* str) const {
	return strCompare(this->str, str) >= 0;
}
bool String::operator<=(const char* str) const {
	return strCompare(this->str, str) <= 0;
}
bool String::operator>=(const String& other) const {
	return strCompare(this->str, other.str) >= 0;
}
bool String::operator<=(const String& other) const {
	return strCompare(this->str, other.str) <= 0;
}

std::istream& operator>>(std::istream& stream, String& string) {
	return string.readFromStream(stream);
}

bool String::getLine(std::istream& stream, String& string) {
	return string.readFromStream(stream, true).good();
}

std::ostream& operator<<(std::ostream& stream, const String& string) {
	stream.write(string.str, string.length);

	return stream;
}

char& String::operator[](const unsigned int& index) {
	assert(index >= 0 && index < this->length);

	return this->str[index];
}

const char& String::operator[](const unsigned int& index) const {
	assert(index >= 0 && index < this->length);

	return this->str[index];
}

int String::indexOf(const char* str) const{
	unsigned int strLength = strLen(str);
	int index = -1;

	for (unsigned int i = 0; i < this->length; i++)
	{
		if (i + strLength - 1 >= this->length) {
			return index;
		}

		if (this->str[i] == str[0]) {
			index = i;
			for (unsigned int j = 1; j < strLength; j++)
			{
				if (this->str[i + j] != str[j]) {
					index = -1;
					break;
				}
			}

			if (index != -1) {
				return index;
			}
		}

	}

	return index;
}

int String::indexOf(const char& character) const{
	for (unsigned int i = 0; i < this->length; i++)
	{
		if (this->str[i] == character) {
			return i;
		}
	}

	return -1;
}

int String::indexOf(const String& other) const{
	return this->indexOf(other.str);
}

String String::reverse() const {
	String res;

	for (int i = this->length - 1; i >= 0; i--)
	{
		res += this->str[i];
	}

	return res;
}

String String::substring(const unsigned int& first, const unsigned int& _length) const {
	assert(_length >= 0 && first >= 0 && first + _length <= this->length);

	String res;

	for (unsigned int i = first; i < first + _length; i++)
	{
		res += this->str[i];
	}

	return res;
}

Vector<String> String::split(const String& delimiter) const {
	Vector<String> res;

	if (!delimiter.getLength()) {
		if (this->length) {
			res.pushBack(*this);
		}
		return res;
	}

	String currWord;

	for (unsigned int i = 0; i < this->length; i++)
	{
		if (delimiter[0] == this->str[i] && i + delimiter.getLength() <= this->length) {
			bool wasDelimFound = true;
			for (unsigned short j = 1; j < delimiter.getLength(); j++)
			{
				if (delimiter[j] != this->str[i + j]) {
					wasDelimFound = false;
					break;
				}
			}

			if (wasDelimFound) {
				if (currWord.length) {
					res.pushBack(currWord);
				}
				currWord = "";
				i += delimiter.getLength() - 1;
			}
			else {
				currWord += this->str[i];
			}
		}
		else {
			currWord += this->str[i];
		}
	}

	if (currWord.length) {
		res.pushBack(currWord);
	}

	return res;
}

unsigned int String::getLength() const {
	return this->length;
}
unsigned int String::getCapacity() const {
	return this->capacity;
}

const char* const String::getConstChar() const{
	return this->str;
}

void String::reserve(unsigned int capacity) {
	capacity = max(capacity, this->defaultCapacity);

	this->capacity += capacity * 2;

	this->copy(*this);
}

void String::copy(const String& other) {
	this->capacity = other.capacity;
	this->length = other.length;

	char* newStr = new char[this->capacity];

	strCopy(other.str, newStr);

	this->deleteInternals();
	this->str = newStr;
}

void String::deleteInternals() {
	delete[] this->str;
}

String String::toString(double num, unsigned short precision) {

	assert(precision > 0 && precision < 20);

	String res;

	if (num < 0) {
		num *= -1;
		res += '-';
	}

	res += numToString(num);

	num -= (unsigned long long)num;

	if (num == 0 || precision == 0) {
		return res;
	}

	res += '.';

	unsigned short currPrecision = 0;

	while (currPrecision != precision)
	{
		num *= 10;
		res += (unsigned short)(num) + '0';
		num -= (unsigned short)num;
		currPrecision++;
	}

	return res;
}

String String::join(const Vector<String>& elements, const String& delimiter) {
	String res;
	unsigned int elsSize = elements.getSize();
	for (unsigned int i = 0; i < elsSize; i++)
	{
		res += elements[i];
		if (i != elsSize - 1) {
			res += delimiter;
		}
	}

	return res;
}

std::istream& String::readFromStream(std::istream& stream, bool whileNewLine) {
	char currSymbol;
	bool symbolNotNewLine;
	unsigned int index = 0;
	unsigned int currSize = 100;
	char* tempStr = new char[currSize];

	do {
		stream.get(currSymbol);
		symbolNotNewLine = currSymbol != '\n' && currSymbol != '\r\n' && currSymbol != '\r';

		if (index % 100 == 0 && index != 0) {
			currSize += 100;
			char* extendedStr = new char[currSize];

			tempStr[index - 1] = '\0';
			strcpy_s(extendedStr, currSize - 100, tempStr);
			delete[] tempStr;
			tempStr = extendedStr;
		}

		tempStr[index++] = currSymbol;
	} while (stream.good() && (whileNewLine ? symbolNotNewLine : currSymbol != ' ' && symbolNotNewLine));

	tempStr[index - 1] = '\0';
	*this = tempStr;
	delete[] tempStr;

	return stream;
}

int String::isNumeric(const String& value) {
	if (!value.getLength()) {
		return -1;
	}

	int dotIndex = value.indexOf('.');

	if (dotIndex == 0 || dotIndex == value.getLength() - 1) {
		return -1;
	}

	for (unsigned int i = 0; i < value.getLength(); i++)
	{
		if ((value[i] < '0' || value[i] > '9') && value[i] != '.' && (value[i] == '-' ? i != 0 : true)) {
			return -1;
		}
	}

	return dotIndex != -1 ? 1 : 0;
}

double String::toDouble(const String& num) {
	if (String::isNumeric(num) != 1) {
		throw std::invalid_argument("Error: \"toDouble\" method expects doubles only!");
	}
	int dotIndex = num.indexOf('.');

	double exponent = String::toLong(num.substring(0, dotIndex));
	double fraction = String::toLong(num.substring(dotIndex + 1, num.getLength() - dotIndex - 1));

	while (fraction > 1) {
		fraction /= 10;
	}

	return num[0] == '-' ? exponent - fraction : exponent + fraction;
}

int String::toInt(const String& num) {
	if (String::isNumeric(num) != 0) {
		throw std::invalid_argument("Error: \"toInt\" method expects integers only!");
	}

	return String::toLong(num);
}

long long String::toLong(const String& num) {
	if (String::isNumeric(num) != 0) {
		throw std::invalid_argument("Error: \"toLong\" method expects long long only!");
	}

	unsigned int numLength = num.getLength();
	long long res = 0;
	unsigned int i = num[0] == '-' ? 1 : 0;

	for (; i < numLength; i++)
	{
		res += num[i] - '0';

		if (i != numLength - 1) {
			res *= 10;
		}
	}

	if (num[0] == '-') {
		res *= -1;
	}

	return res;
}

#endif // !STRING_CPP
