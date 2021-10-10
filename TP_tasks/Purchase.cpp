#include "Purchase.h"

Purchase::Purchase() : product(), quantity_product(0), purchase_price(0) {}

Purchase::Purchase(Product& _product, int _quantity_product, double _purchase_price) :
	product(_product), quantity_product(_quantity_product), purchase_price(_purchase_price) {}

Purchase::Purchase(const Purchase& purchase) : product(purchase.product), quantity_product(purchase.quantity_product), 
			purchase_price(purchase.purchase_price) {}


