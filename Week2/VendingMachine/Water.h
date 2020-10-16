#ifndef WATER_H
#define WATER_H
#include "Item.h"

class Water :
	public Item
{
	private:
		int bottleSize;
	public:
		Water(const double&, const int&);

		void setBottleSize(const int&);
		int getBottleSize(const int&) const;
};

#endif

