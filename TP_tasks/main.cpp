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

	cout << "����� ����������!" << endl;
	while (1)
		menu();
}

void base_products() {

	products.push_back(Product("������", 250));
	products.push_back(Product("������� ����", 50));
	products.push_back(Product("������", 100));
	products.push_back(Product("��������", 50));
	products.push_back(Product("���", 140));
	products.push_back(Product("������", 140));
	products.push_back(Product("����", 60));
	products.push_back(Product("�����", 60));
	products.push_back(Product("�������", 30));
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
			cout << "������� ���� ��������� �������!" << endl;
		}
		break;
	case 0:
		cout << "������� �� �������!" << endl;
		exit(0);
	}
}

void print_menu() {
	cout << endl;
	cout << "�������� ��������:" << endl;
	cout << "  1. ��������� �������" << endl;
	cout << "  ---" << endl;
	cout << "  0. ��������� ������������" << endl;
}

bool selection_products() {
	if (products.size() == 0)
	{
		cout << "� �������� ��� ���������, �������� ���� ���������." << endl;
		return false;
	}
	else {
		output_products();
		cout << "   ---" << endl;
		cout << "  0. ";
		cout.width(15);
		cout << "��������� ����" ;
		cout << endl << endl;
		while (1) {
			cout << "�������� ����� " << endl;
			int number_product = input_number();
			if (number_product == 0) break;
			else if (checking_number_products(number_product) == true)
			{
				Check* check = new Check;
				check->input_purchase(products.at(number_product - 1));
				purchase.push_back(check);
			}
			else
				cout << "� �������� ��� ������ ��������. " << endl;
		}
		return true;
	}	
}

void output_purchase() {
	cout << endl << "������� ������ ���������:" << endl;
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
	cout << "  �����:";
	cout.width(31);
	cout << total_purchase << endl << endl;
}

void output_check() {
	cout << "����� ���? 1 - ��, 2 - ���" << endl;
	double one_purchase, total_purchase = 0;
	int punkt_menu = input_number();
	ofstream fout("Check.txt");
	switch (punkt_menu)
	{
	case 1:
		fout << "         �. �����-���������" << endl;
		fout << "      ��-� ������� ������, �.60" << endl;
		fout << "            �������� ���" << endl << endl;
		for (int i = 0; i < purchase.size(); i++) {
			fout << i + 1 << ". ";
			purchase[i]->output_to_file(fout);
			one_purchase = purchase[i]->getPurchasePrice();
			total_purchase += one_purchase;
		}
		fout << "------------------------------------" << endl;
		fout << "�����:";
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
	cout << endl << "�������� � �������:" << endl;
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
			cout << "������ ����� �����������. ��������� ����." << endl << ">> ";
	}
}

bool intSigned(const string& s) // �������� �� ������ ����� � ������
{
	if (s.find_first_not_of("0123456789", 0) == string::npos)
		return true;
	else
		return false;
}

bool doubleSigned(const string& s) // �������� �� ������ ����� � ������
{
	if (s.find_first_not_of("0123456789.", 0) == string::npos)
		return true;
	else
		return false;
}

bool stringSigned(const string& s) // �������� �� ����� � ������
{
	if (s.find_first_not_of(" qwertyuioplkjhgfdsamnbvcxzPOIUYTREWQLKJHGFDSAMNBVCXZ", 0) == string::npos)
		return true;
	else
		return false;
}