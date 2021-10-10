#pragma once
#include <iostream>
#include <string>
using namespace std;

class Product
{
private:
	string name_product;
	double cost_product;
public:
	Product();
	Product(string _name_producuct, double _cost);
	Product(const Product& product);
	~Product() = default;

	void output_console();

	void setNameProduct(string _name_product){ name_product = _name_product;}
	void setCostProduct(double _cost) { cost_product = _cost; }
	string getNameProduct() { return name_product;}
	double getCostProduct() { return cost_product; }

	bool operator==(Product& product);

};

