#include <iostream>
#include <Windows.h>
#include <string>

using namespace std;

int check() {
	int input;
	while (true) {
		cin >> input;
		if (cin.fail()) {
			cin.clear();
			cout << "Некорректный ввод.\nПовторите попытку: ";
		}
		else return input;
		cin.ignore(32767, '\n');
	}
	return input;
}

int selection(int first, int last) {
	int input;
	while (true) {
		cin >> input;
		if (cin.fail() || input < first || input > last)
		{
			cin.clear();
			cout << "Данный пункт отсутствует" << endl << "  > ";
		}
		else return input;
		cin.ignore(32767, '\n');
	}
	return input;
}

string decToBin(int dec)
{
	int minus = 0/*, i = 0*/;
	string bin = "";

	if (dec == 0) { bin.push_back('0'); }
	if (dec < 0) { dec *= (-1); minus = 1; }
	while (dec > 0)
	{
		if (dec % 2 == 0) {
			bin.push_back('0');
		}
		else {
			bin.push_back('1');
		}
		dec /= 2;
	}
	if (minus) bin.push_back('-');
	reverse(bin.begin(), bin.end());
	return bin;
}

void zag() {
	cout.width(4);
	cout << "№" << "|";
	cout.width(30);
	cout << "2CC" << "|";
	cout.width(30);
	cout << "length_local" << "|";
	cout.width(30);
	cout << "length_max" << "|" << endl;
	for (int i = 1; i < 99; i++) { cout << "_"; }
	cout << endl;
}

void total(int output) {
	for (int i = 1; i < 99; i++) { cout << "_"; }
	cout << endl << endl;
	cout << "Максимально возможная последовательность единиц при замене одного 0 на 1 равна: "<< output << endl;;
	for (int i = 1; i < 99; i++) { cout << "_"; }
	cout << endl;
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	string input, buf, res, one;
	int length_main, length_local, length_local_ctr, length_max, zero_poz, next_byte;
	bool zero_found;

	cout << "Добро пожаловать! Начнём ввод?" << endl << "[1 - Да, 0 - Нет]" << endl << "  > ";

	while (selection(0, 1)) {

		system("cls");
		cout << "Введите число: ";
		int dec = check();
		input = decToBin(dec);

		cout << "Число в двоичной СС: ";
		cout << input << endl << endl;

		zag();

		while (true) {
			next_byte = 0, zero_found = 0, zero_poz = -1;
			length_max = 0, length_main = input.length();

			for (int i = 0; i < length_main; i++) {

				//поиск и замена одого 0 на 1
				zero_found = 0;
				one = "1";
				res = "";
				for (int j = i; j < length_main; j++) {
					if (input[j] == '0' && j > zero_poz) {
						if (!zero_found) {
							zero_poz = j;
							zero_found = 1;
							//input[i] = '1';
							buf.assign(input, 0, j);
							res += buf;
							res += one;
							buf.assign(input, j + 1, (length_main - res.length()));
							res += buf;
							//break;
						}
					}
				}

				if (res.empty() && (!input.empty())) res += input;

				//подсчёт максимальной длины последовательности единиц
				if (!res.empty()) {
					length_local_ctr = 0, length_local = 0;
					for (int y = 0; y < length_main; y++) {
						if (res[y] == '0' && length_local_ctr) {
							/*break;*/
							if (length_local_ctr > length_local) length_local = length_local_ctr;
							length_local_ctr = 0;
						}

						if (res[y] == '1') {
							length_local_ctr++;
						}
					}
					if (length_local_ctr > length_local) length_local = length_local_ctr;
					if (length_local > length_max) length_max = length_local;

					//вывод промежуточного результата
					cout.width(4);
					cout << i << "|";
					cout.width(30);
					cout << res << "|";
					cout.width(30);
					cout << length_local << "|";
					cout.width(30);
					cout << length_max << "|";
					cout << endl;
				}
				if (!zero_found) break;
			}
			//cout << res;
			break;
		}
		total(length_max);

		cout << endl;
		cout << "Продолжить работу?" << endl << "[1 - Да, 0 - Нет]" << endl << "  > ";
	}
	return 0;
}