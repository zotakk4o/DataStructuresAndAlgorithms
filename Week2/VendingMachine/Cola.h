#ifndef COLA_H
#define COLA_H

#include "Flavoured.h"
#include "Item.h"

class Cola :
	public Flavoured,
	public Item
{
	public:
		Cola(const String&, const double&);
};

#endif
