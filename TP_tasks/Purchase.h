#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Product.h"
using namespace std;


class Purchase
{
private:
	Product product;
	int quantity_product;
	double  purchase_price;

public:

	Purchase();
	Purchase(Product& product, int _quantity_product, double _purchase_price);
	Purchase(const Purchase& purchase);
	~Purchase() = default;
	
	void setProduct(Product& _product) { product = _product; }
	void setQuantityProduct(int _quantity_product) { quantity_product = _quantity_product; }
	void setPurchasePrice(double _purchase_price) { purchase_price = _purchase_price; }

	Product& getProduct() { return product; }
	int getQuantityProduct() { return quantity_product; }
	double getPurchasePrice() { return purchase_price; }

	virtual void input_purchase(Product&) = 0;

	virtual void output_product_receipt() = 0;

	virtual void output_to_file(ofstream&) = 0;

};

