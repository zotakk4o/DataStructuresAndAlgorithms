#ifndef MATHHELPER_H
#define MATHHELPER_H

#include "String.h"
class MathHelper
{
	private:
		static double calculateOperation(const double&, const double&, const char&);
	public:
		static double calculateExpression(const String&); //Strict space separation between numbers and operators required

};

#endif

