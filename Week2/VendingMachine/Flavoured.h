#ifndef FLAVOURED_H
#define FLAVOURED_H

#include "include/String.h"
class Flavoured
{
	protected:
		String flavour;
		Flavoured(const String&);
		Flavoured(const Flavoured&) = delete;
		Flavoured& operator=(const Flavoured&) = delete;

	public:
		virtual ~Flavoured();
		void setFlavour(const String&);
		String getFlavour() const;
};

#endif