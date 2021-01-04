#ifndef CONFIG_H
#define CONFIG_H

#include "include/String.h"
#include "include/Vector.cpp"
#include "../commands/BaseClasses/Command.h"
#include "../commands/BaseClasses/CommandParameter.h"
#include <iostream>

class Config {
	public:
		static const char commandDelimiter;
		static std::istream& inputStream;
		static const Vector<Command*> commands;
		static const Vector<CommandParameter*> commandsParameter;
		virtual ~Config() = 0;
};
 
#endif