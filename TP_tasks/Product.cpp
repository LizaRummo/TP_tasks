#include "Product.h"

bool doubleSigned(const string& s);
bool stringSigned(const string& s);

Product::Product() : name_product("uncounted"), cost_product(0) {}

Product::Product(string _name_producuct, double _cost) : name_product(_name_producuct), cost_product(_cost) {}

Product::Product(const Product& product) : name_product(product.name_product), cost_product(product.cost_product) {}

void Product::output_console() {
	cout.width(15);
	cout << getNameProduct();
	cout.width(5);
	cout << getCostProduct() << endl;
}

bool Product::operator==(Product& product) {
	return name_product == product.getNameProduct() && cost_product == product.getCostProduct();
}
