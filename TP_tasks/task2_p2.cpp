#include <iostream>
#include <Windows.h>
#include <string>

using namespace std;

//реализация стека в старой лабе

struct Node{
    string val;
    Node* next;

    Node(string _val) : val(_val), next(nullptr) {}
};

struct list {
    Node* first;
    Node* last;

    list() : first(nullptr), last(nullptr) {}

    bool is_empty() {
        return first == nullptr;
    }

    void push_back(string _val) {
        Node* p = new Node(_val);
        if (is_empty()) {
            first = p;
            last = p;
            return;
        }
        last->next = p;
        last = p;
    }

    void print() {
        if (is_empty()) return;
        Node* p = first;
        while (p) {
            cout << p->val << " ";
            p = p->next;
        }
        cout << endl;
    }
};

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

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	return 0;
}