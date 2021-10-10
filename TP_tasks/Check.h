#pragma once
#include <fstream>
#include "Purchase.h"
class Check :
    public Purchase
{
public:
	Check();
	Check(Product& _product, int _quantity_product, double _purchase_price);
	Check(const Check& check);
	~Check() = default;

	void setProduct(Product& _product) { Purchase::setProduct(_product); }
	void setQuantityProduct(int _quantity_product) { Purchase::setQuantityProduct(_quantity_product); }
	void setPurchasePrice(double _purchase_price) { Purchase::setPurchasePrice(_purchase_price); }

	Product& getProduct() { return Purchase::getProduct(); }
	int getQuantityProduct() { return Purchase::getQuantityProduct(); }
	double getPurchasePrice() { return Purchase::getPurchasePrice(); }

	virtual void input_purchase(Product& product);
	virtual void output_product_receipt();

	virtual void output_to_file(ofstream&);
};

