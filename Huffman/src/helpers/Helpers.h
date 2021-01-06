#ifndef HELPERS_H
#define HELPERS_H

#include "include/String.h"

/// <summary>
/// Class responsible for converting binary sequences to chars and vice-versa
/// </summary>
class Helpers
{
	public:
		/// <summary>
		/// Coverts a 8-bit binary sequence to a character
		/// </summary>
		/// <param>const String& the BINARY string to be converted</param>
		/// <returns>unsigned char</returns>
		static unsigned char BinaryStringToChar(const String&);

		/// <summary>
		/// Coverts a character to an 8-bit binary sequence
		/// </summary>
		/// <param>unsigned char the character to be converted</param>
		/// <returns>String</returns>
		static String CharToBinaryString(unsigned char);

		/// <summary>
		/// Coverts a character to an ASCII char
		/// </summary>
		/// <param>String the code to be debugged</param>
		/// <returns>String</returns>
		static String convertCodeForDebugging(String);

		/// <summary>
		/// Stops the currently running program.
		/// </summary>
		static void exitProgram();
		virtual ~Helpers() = 0;
};

#endif

