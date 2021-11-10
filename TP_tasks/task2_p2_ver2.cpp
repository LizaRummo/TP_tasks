#include <iostream>
#include <Windows.h>
#include <string>

using namespace std;

class StackInArray {
private:
    unsigned int sizeOfStack;
	unsigned int maxSize;
    string* array;


public:
    StackInArray(const unsigned int maxSize) {
		this->sizeOfStack = 0;
		this->maxSize = maxSize;
		this->array = new string[maxSize];
    }
    ~StackInArray(){ delete[] array;}
    void push(const string newElement) {
        array[sizeOfStack] = newElement;
        sizeOfStack++;
    }
    void pop() {sizeOfStack--;}
	void output() {
		string* e = array;
		cout << "top" << endl;
		for (int i = 0; i < maxSize; i++) {
			if (i + 1 > sizeOfStack) cout << "free" << endl;
			else {
				cout << array[i] << endl;
			}
		}
	}


    string getTop() {return array[sizeOfStack - 1]; }
    unsigned int getSize() {
        return sizeOfStack;
    }
};

struct Node {
	StackInArray* stack_ptr;
	Node* next;

	Node(StackInArray* _stack_ptr) : stack_ptr(_stack_ptr), next(nullptr) {}
};

class List {
private:
	Node* first;
	Node* last;

public:
	List() : first(nullptr), last(nullptr) {}

	bool is_empty() { return first == nullptr; }	//Функция проверки наличия узлов в списке
	void push_back(StackInArray* _stack_ptr);
	void print();
	void remove_first();
	void remove_last();
	Node* operator[] (const int index);
};

//Функция добавления элемента в конец списка
void List::push_back(StackInArray* _stack_ptr) {
	Node* p = new Node(_stack_ptr);
	if (is_empty()) {
		first = p;
		last = p;
		return;
	}
	last->next = p;
	last = p;
}

//Функция вывода всего списка
void List::print() {
	if (is_empty()) return;
	Node* p = first;
	while (p) {
		first->stack_ptr->output();
		p = p->next;
	}
}

//Функция удаления первого узла
void List::remove_first() {
	if (is_empty()) return;
	Node* p = first;
	first = p->next;
	delete p;
}

//Функция удаления последнего узла
void List::remove_last() {
	if (is_empty()) return;
	if (first == last) {
		remove_first();
		return;
	}
	Node* p = first;
	while (p->next != last) p = p->next;
	p->next = nullptr;
	delete last;
	last = p;
}

Node* List::operator[] (const int index) {
	if (is_empty()) return nullptr;
	Node* p = first;
	for (int i = 0; i < index; i++) {
		p = p->next;
		if (!p) return nullptr;
	}
	return p;
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

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	return 0;
}