#include <iostream>
#include <Windows.h>
#include <string>

using namespace std;

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	string input, buf, res, one = "1";
	int length_main, length_local = 0, length_local_ctr = 0, length_max = 0, zero_poz=0, next_byte;
	bool zero_found;
	//getline(cin, input);
	//getline(cin, input);

	//перевод в 2сс
	int minus = 0, dec, i = 0;
	string bin = "";
	cout << "Введите число: " ;
	cin >> dec;

	//if (dec < 0) { dec *= (-1); minus = 1; }
	//
	//while (dec > 1)
	//{
	//	bin += (dec % 2) * pow(10, i);		//Присваиваем i-тому разряду остаток от деления
	//	dec /= 2;
	//	i++;
	//}
	//bin += dec * pow(10, i);
	//input = to_string(bin);

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

	cout << "Число в двоичной СС: "; 
	cout << bin << endl << endl;
	//конец перевода в 2сс

	input = bin;

	cout.width(4);
	cout << "№" << "|";
	cout.width(30);
	cout << "2CC (модуль)" << "|";
	cout.width(30);
	cout << "length_local" << "|";
	cout.width(30);
	cout << "length_max" << "|" << endl;
	for (int i = 1; i < 98; i++) { cout << "_"; }
	cout << endl;

	while (true) {
		next_byte = 0;
		zero_found = 0;
		length_main = input.length();
		
		for (int i = 0; i < length_main; i++) {
			
			//cout.width(30);
			//cout << input[i] << " ";

			//if (!(input[i] == '\0' || input[i] == '\n')) {
			//	if (input[i] == '0') {
			//		if (!zero_found) {
			//			buf.assign(input, next_byte, i - (res.length()));
			//			res += buf;
			//			res += one;
			//			next_byte = NULL;
			//			zero_found = 1;
			//			length_local++;
			//			//ctr_err++;
			//		}
			//		if (zero_found) {
			//			if (length_local > length_max)length_max = length_local;
			//			length_local = 0;
			//			buf.assign(input, next_byte, length_main - (res.length()));
			//			//cout << res;
			//			res = "" + buf;
			//		}
			//	}
			//	else {
			//		length_local++;
			//		//cout << res;
			//	}
			//	if (zero_found) {
			//		next_byte = i;
			//		zero_found = 0;
			//	}
			//}else break;
			zero_found = 0;
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

			if (!res.empty()) {
				length_local_ctr = 0; length_local = 0;
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
		}
		cout<< res;
		break;
	}
	return 0;
}