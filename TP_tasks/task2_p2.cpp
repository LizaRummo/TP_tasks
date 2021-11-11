#include <iostream>
#include <Windows.h>
#include <string>

using namespace std;

struct Element {
    string elt;				// элемент
    Element* next;		// указатель на следующий элемент

	//Element() : elt(NULL), next(nullptr) {}
};

class Stack {
private:
    int size;			// кол-во элементов в очереди 
    Element* top;		// указатель на вершину стека
	int size_max;

public:
    Stack(int _size_max) : size(0), size_max(_size_max), top(NULL) {};	// конструктор
    Stack(Stack& stack);				//конструктор копирования
    ~Stack() { /*clear();*/ };			// деструктор

	int getSize_max() { return size_max; }
	int getSize() { return size; }
	Element* getTop() { return top; };
	bool freeSpace() { 
		if (size < size_max) return 1; 
	else return 0; 
	}

    void push(string);
	void pop();
    void output();
    void clear();
};

//Конструктор копирования
Stack::Stack(Stack& stack)
{
	this->top = NULL;
	this->size = 0;
	this->size_max = stack.size_max;
	if (stack.size != 0) {
		//this->copy(stack);
		Element* e = stack.top;		// установка указателя на верхушку
		for (int i = 0; i < stack.size; i++) {
			e = stack.top;				// установка указателя на верхушку
			for (int j = 0; j < stack.size - i - 1; j++) {
				e = e->next;		// просмотр элементов сверху вниз
			}
			push(e->elt);				//запись элемента в копию
		}
	}
}

//Функция очистки
void Stack::clear() {			// просмотр элементов с вершины вниз, удаление элементов от головы по порядку	
	Element* e = top;			// установка указателя на конец очереди
	for (int i = 0; i < size; i++) {	//очередь не пустая
		e = top;				// указатель на конец очереди
		for (int j = 0; j < size - i - 1; j++) {
			e = e->next;		// просмотр элементов с конца очереди до начала
		}
		delete e;				// удаление элемента очереди
	}
	size = 0;
	top = NULL;
 size_max=0;
}

//Функция добавления элементов
void Stack::push(string input) {
		Element* e = new Element();
		e->elt = input;
		e->next = NULL;
		if (size > 0) { //Если стек не пустой
			e->next = top; //Проводим связь от нового элемента, к вершине
		}
		top = e;
		this->size++;
}

//Функция извлечения элемента
void Stack::pop() {			// просмотр элементов с вершины вниз, удаление элементов от головы по порядку	
	if (size) {
		Element* e = top;			// установка указателя на конец 
		top = e->next;
		delete e;				// удаление элемента 
		size--;
	}
}

//Функция вывода стека
void Stack::output() {
	Element* e = top;
	cout.width(10);
	cout << "[top]  ";
	cout << "———" << endl;
	for (int i = 0; i < size_max - size; i++) {
		cout.width(10);
		cout << "[free]  " << endl;
	}
	for (int i = 0; i < size; i++) {
		cout.width(10);
		cout << "[busy]  ";
		cout << e->elt << endl;
		e = e->next;
	}
	cout.width(10);
	cout << "[null]  ";
	cout << "———" << endl;
}


struct Node{
    Stack* stack_ptr;
    Node* next;

    Node(Stack* _stack_ptr) : stack_ptr(_stack_ptr), next(nullptr) {}
};

class List {
private:
    Node* first;
    Node* last;

public:
    List() : first(nullptr), last(nullptr) {}

    bool is_empty() {return first == nullptr;}	//Функция проверки наличия узлов в списке
	void push_back(Stack* _stack_ptr);
	void print();
	void remove_first();
	void remove_last();

	Node* getFirst() { return first; };
	Node* getLast() { return last; };
	Node* operator[] (const int index);
};

//Функция добавления элемента в конец списка
void List::push_back(Stack* _stack_ptr) {
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
	if (is_empty()) { cout << "-is empty-" << endl;  return; }
	int ctr = 0;
	//вывод всех стеков
	Node* p = first;
	while (p) {
		//p->stack_ptr->output();
		p = p->next;
		ctr++;
	}
	//p = first;
	int ctr_loc = ctr;
	for (int i = 0; i < ctr; i++) {
		p = first;
		for (int j = 0; j < ctr_loc-1; j++) {
			p = p->next;
		}
		p->stack_ptr->output();
		ctr_loc--;
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

//

List list;
Stack* stack_ptr_glob;
int stack_size;

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

void add_elt() {
	string input;
	cout << "Введите значение нового элемента: ";
	getline(cin, input);
	getline(cin, input);
	if (stack_ptr_glob->freeSpace()) stack_ptr_glob->push(input);
	else {
		stack_ptr_glob = new Stack(stack_size);
		list.push_back(stack_ptr_glob);
		stack_ptr_glob->push(input);
	}
}

void del_elt() {
	stack_ptr_glob->pop();
	if (stack_ptr_glob->getTop() == NULL) {
		list.remove_last();
		if (!list.is_empty()) {
			stack_ptr_glob = list.getLast()->stack_ptr;
			stack_ptr_glob->getTop();
		}
		else cout << "-no elements to pop()-" << endl;
	}
}

void print_menu() {
	cout << endl << "Выберите пункт меню:" << endl;
	cout << "  1. Добавление элемента" << endl;
	cout << "  2. Удаление элемнта" << endl;
	cout << "  3. Вывод текущего стека на экран" << endl;
	cout << "  ---" << endl;
	cout << "  0. Выход из программы" << endl;
	cout << "  >> ";
}

int menu() {
//	int point;

	while (1) {
		print_menu();
		switch (selection(0, 3)) {
		case 1:
		{
			add_elt();
			break;
		}
		case 2:
		{
			del_elt();
			break;
		}
		case 3:
		{
			list.print();
			break;
		}
		case 0:
			return (0);
		}
	}
}



int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	cout << "Задайте размер стека: ";
	stack_size = check();
	stack_ptr_glob = new Stack(stack_size);
	list.push_back(stack_ptr_glob);

	menu();

	return 0;
}