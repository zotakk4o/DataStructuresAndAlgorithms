#ifndef ITEM_H
#define ITEM_H

class Item {
	protected:
		double price;
		Item(const double&);
		Item(const Item&) = delete;
		Item& operator=(const Item&) = delete;

	public:
		virtual ~Item();
		void setPrice(const double&);
		double getPrice() const;
};

#endif
