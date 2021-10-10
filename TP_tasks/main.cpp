#include <iostream>
#include <vector>
#include <string>
#include <conio.h>
#include <fstream>
using namespace std;

#include "Product.h"
#include "Purchase.h"
#include "Check.h"

vector<Product> products; 
vector<Purchase*> purchase;

bool doubleSigned(const string&);
bool stringSigned(const string&);
bool intSigned(const string&);
bool checking_number_products(int);
int input_number();
void base_products();

void menu();
void print_menu();

bool selection_products();
void output_purchase();
void calculating_total_purchase();
void output_check();

void output_products();

void main()
{
	setlocale(LC_ALL, "rus");
	base_products();

	cout << "Добро пожаловать!" << endl;
	while (1)
		menu();
}

void base_products() {

	products.push_back(Product("Курица", 250));
	products.push_back(Product("Куриные яйца", 50));
	products.push_back(Product("Молоко", 100));
	products.push_back(Product("Макароны", 50));
	products.push_back(Product("Сыр", 140));
	products.push_back(Product("Творог", 140));
	products.push_back(Product("Хлеб", 60));
	products.push_back(Product("Курпа", 60));
	products.push_back(Product("Капуста", 30));
}

void menu() {
	print_menu();
	int punkt_menu = input_number();
	switch (punkt_menu)
	{
	case 1:
		if (selection_products() == true) {
			output_purchase();
			calculating_total_purchase();
			output_check();
			system("cls");
			cout << "Покупка была совершена успешно!" << endl;
		}
		break;
	case 0:
		cout << "Спасибо за покупку!" << endl;
		exit(0);
	}
}

void print_menu() {
	cout << endl;
	cout << "Выберите действие:" << endl;
	cout << "  1. Совершить покупку" << endl;
	cout << "  ---" << endl;
	cout << "  0. Завершить обслуживание" << endl;
}

bool selection_products() {
	if (products.size() == 0)
	{
		cout << "В магазине нет продуктов, приносим свои извинения." << endl;
		return false;
	}
	else {
		output_products();
		cout << "   ---" << endl;
		cout << "  0. ";
		cout.width(15);
		cout << "Закончить ввод" ;
		cout << endl << endl;
		while (1) {
			cout << "Выберите пункт " << endl;
			int number_product = input_number();
			if (number_product == 0) break;
			else if (checking_number_products(number_product) == true)
			{
				Check* check = new Check;
				check->input_purchase(products.at(number_product - 1));
				purchase.push_back(check);
			}
			else
				cout << "В магазине нет такого продукта. " << endl;
		}
		return true;
	}	
}

void output_purchase() {
	cout << endl << "Текущий список продуктов:" << endl;
	for (int i = 0; i < purchase.size(); i++) {
		cout << "  " << i + 1 << ". ";
		purchase[i]->output_product_receipt();
	}
}

void calculating_total_purchase() {
	double one_purchase, total_purchase = 0;
	for (int i = 0; i < purchase.size(); i++) {
		one_purchase = purchase[i]->getPurchasePrice();
		total_purchase += one_purchase;
	}
	cout << "  ---" << endl;
	cout << "  ИТОГО:";
	cout.width(31);
	cout << total_purchase << endl << endl;
}

void output_check() {
	cout << "Нужен чек? 1 - Да, 2 - Нет" << endl;
	double one_purchase, total_purchase = 0;
	int punkt_menu = input_number();
	ofstream fout("Check.txt");
	switch (punkt_menu)
	{
	case 1:
		fout << "         г. Санкт-Петербург" << endl;
		fout << "      пр-т Маршала Жукова, д.60" << endl;
		fout << "            КАССОВЫЙ ЧЕК" << endl << endl;
		for (int i = 0; i < purchase.size(); i++) {
			fout << i + 1 << ". ";
			purchase[i]->output_to_file(fout);
			one_purchase = purchase[i]->getPurchasePrice();
			total_purchase += one_purchase;
		}
		fout << "------------------------------------" << endl;
		fout << "ИТОГО:";
		fout.width(31);
		fout << total_purchase << endl << endl;
		fout.close();
		break;
	case 2:
		fout.close();
		break;
	case 3:
		exit(0);
	}
}

void output_products() {
	cout << endl << "Продукты в наличии:" << endl;
	for (int i = 0; i < products.size(); i++) {
		cout << "  " << i + 1 << ". ";
		products[i].output_console();
	}
	cout << endl;
}

bool checking_number_products(int number_products) {
	if ((number_products <= products.size())&& (number_products>0))
		return true;
	else
		return false;
}

int input_number() {
	string number_s;
	while (1)
	{
		cout << ">> ";
		cin >> number_s;
		if (intSigned(number_s) == true)
		{
			int number = stoi(number_s);
			return number;
		}
		else
			cout << "Данный пункт отсутствует. Повторите ввод." << endl << ">> ";
	}
}

bool intSigned(const string& s) // проверка на только цифры в строке
{
	if (s.find_first_not_of("0123456789", 0) == string::npos)
		return true;
	else
		return false;
}

bool doubleSigned(const string& s) // проверка на только цифры в строке
{
	if (s.find_first_not_of("0123456789.", 0) == string::npos)
		return true;
	else
		return false;
}

bool stringSigned(const string& s) // проверка на буквы и пробел
{
	if (s.find_first_not_of(" qwertyuioplkjhgfdsamnbvcxzPOIUYTREWQLKJHGFDSAMNBVCXZ", 0) == string::npos)
		return true;
	else
		return false;
}