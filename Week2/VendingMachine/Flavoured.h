#ifndef FLAVOURED_H
#define FLAVOURED_H

#include "include/String.h"
class Flavoured
{
	protected:
		String flavour;

	public:
		Flavoured(const String&);
		virtual ~Flavoured() = 0;
		void setFlavour(const String&);
		String getFlavour() const;
};

#endif