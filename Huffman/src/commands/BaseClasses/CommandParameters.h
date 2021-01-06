#ifndef COMMANDPARAMETERS_H
#define COMMANDPARAMETERS_H

#include "include/String.h"

/// <summary>
/// Base Class, defining the main properties of a command
/// </summary>
class CommandParameters{
	public:
		/// <summary>
		/// Specifies the expected input parameters including the keyword, by default a single parameter is expected - the keyword
		/// </summary>
		/// <returns>unsigned int</returns>
		virtual unsigned int getKeywordsCount() const;

		/// <summary>
		/// Decode a given BINARY string
		/// </summary>
		/// <param>Vector<String*>& the expected parameters</param>
		virtual void execute(Vector<String*>&) const = 0;

		/// <summary>
		/// Gives the keyword of the command to be executed
		/// </summary>
		/// <returns>String</returns>
		virtual String toString() const = 0;

		/// <summary>
		/// Checks whether a command is valid and ready to be executed
		/// </summary>
		/// <param>const Vector<String>& the needed parameters and keyword</param>
		/// <returns>bool</returns>
		bool isValid(const Vector<String>&) const;
};

#endif