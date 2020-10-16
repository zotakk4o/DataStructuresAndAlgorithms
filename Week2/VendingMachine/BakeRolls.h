#ifndef BAKEROLLS_H
#define BAKEROLLS_H

#include "Flavoured.h"
#include "Item.h"

class BakeRolls :
	public Flavoured,
	public Item
{
	public:
		BakeRolls(const String&, const double&);
};

#endif

