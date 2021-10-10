#include "Check.h"

bool intSigned(const string& s);

Check::Check() : Purchase(){}

Check::Check(Product& _product, int _quantity_product, double _purchase_price) :
	Purchase(_product, _quantity_product, _purchase_price) {}

Check::Check(const Check& check) : Purchase(check) {}

void Check::input_purchase(Product& product) {

	Purchase::getProduct().setNameProduct(product.getNameProduct());
	Purchase::getProduct().setCostProduct(product.getCostProduct());
	string _quantity_product;
	cout << "Количество: ";
	cin >> _quantity_product;
	if (intSigned(_quantity_product) == true)
		Purchase::setQuantityProduct(stoi(_quantity_product));
	else
		Purchase::setQuantityProduct(0);

	Purchase::setPurchasePrice(product.getCostProduct() * Purchase::getQuantityProduct());
}

void Check::output_product_receipt() {
	cout.width(15);
	cout << Purchase::getProduct().getNameProduct() ;
	cout.width(4);
	cout << Purchase::getQuantityProduct();
	cout << " x ";
	cout.width(4);
	cout << Purchase::getProduct().getCostProduct();
	cout << " = " ;
	cout.width(5);
	cout << Purchase::getPurchasePrice();
	cout << endl;
}

void Check::output_to_file(ofstream& fout){
	if (!fout.is_open())
		cout << "/t Файл Check.txt не открыт" << endl;
	else {
		fout.width(15);
		fout << Purchase::getProduct().getNameProduct();
		fout.width(4);
		fout << Purchase::getQuantityProduct();
		fout << " x ";
		fout.width(4);
		fout << Purchase::getProduct().getCostProduct();
		fout << " = ";
		fout.width(5);
		fout << Purchase::getPurchasePrice();
		fout << endl;
	}
}