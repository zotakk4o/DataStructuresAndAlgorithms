#ifndef STRING_H
#define STRING_H
#include<ostream>
#include "Vector.cpp"

class String {
	private:
		char* str;
		unsigned int length;
		unsigned int capacity;
		static const unsigned short defaultCapacity;

		void reserve(unsigned int = 0);
		void copy(const String& other);
		void deleteInternals();
		std::istream& readFromStream(std::istream&, bool = false);
		static const char* noFreeMemErr;
	public:
		String(const char&);
		String(const char* = "");
		String(const String&);
		~String();

		String& operator=(const String&);
		String& operator+=(const String&);
		String& operator+=(const char*);
		String& operator+=(const char&);
		String operator+(const String&) const;
		String operator+(const char*) const;
		String operator+(const char&) const;

		bool operator==(const String&) const;
		bool operator==(const char*) const;
		bool operator!=(const char*) const;
		bool operator!=(const String&) const;
		bool operator>(const String&) const;
		bool operator>(const char*) const;
		bool operator<(const char*) const;
		bool operator<(const String&) const;
		bool operator>=(const char*) const;
		bool operator<=(const char*) const;
		bool operator>=(const String&) const;
		bool operator<=(const String&) const;

		char& operator[](const unsigned int&);
		const char& operator[](const unsigned int&) const;

		static bool getLine(std::istream&, String&);
		friend std::istream& operator>>(std::istream&, String&);
		friend std::ostream& operator<<(std::ostream&, const String&);

		int indexOf(const char*) const;
		int indexOf(const char&) const;
		int indexOf(const String&) const;

		static int isNumeric(const String&);
		static String toString(double, unsigned short = 6);
		static double toDouble(const String&);
		static int toInt(const String&);
		static long long toLong(const String&);
		static String join(const Vector<String>&, const String& = ',');
		String reverse() const;
		String substring(const unsigned int& first, const unsigned int& length) const;
		Vector<String> split(const String& = ',') const;

		unsigned int getLength() const;
		unsigned int getCapacity() const;
		const char* const getConstChar() const;
};

#endif // !STRING_H
