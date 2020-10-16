#ifndef CROISSANT_H
#define CROISSANT_H

#include "Flavoured.h"
#include "Item.h"

class Croissant :
	public Flavoured,
	public Item
{
	public:
		Croissant(const String&, const double&);
};

#endif
