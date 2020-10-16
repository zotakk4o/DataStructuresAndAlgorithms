#ifndef ITEM_H
#define ITEM_H

class Item {
	protected:
		double price;

	public:
		Item(const double&);
		virtual ~Item() = 0;
		void setPrice(const double&);
		double getPrice() const;
};

#endif
