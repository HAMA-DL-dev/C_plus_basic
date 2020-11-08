#include <iostream>
using namespace std;

class Stack {
private:
	int N;
	int* stack;
	int top;

public:
	Stack(int size);
	~Stack();
	void push(int value);
	void pop();
	int readTop();
	void checkStack();
	bool isEmpty();
};

Stack::Stack(int size = 3) {
	N = size;
	stack = new int[N];
	top = -1;
}

Stack::~Stack() {
	delete[]stack;
}

bool Stack::isEmpty() {
	return top == -1;
}

void Stack::push(int value) {
	if (top == (N - 1))
		cout << " stack is full " << endl;
	else
		stack[top++] = value;
}

int Stack::readTop() {
	cout << "top value: " << top << endl;
	return top;
}

void Stack::pop() {
	if (isEmpty())
		cout << "stack is empty" << endl;

	else
		top--;
}

void Stack::checkStack() {
	if (top > -1) {
		for (int i = 0; i < top + 1; i++)
			cout << stack[i] << " ";
		cout << endl;
		cout << "Total number of Data is " << (top + 1);
	}
	cout << endl;
	readTop();
	cout << endl;
}


int main() {
	Stack a;

	a.pop();
	a.push(5);
	a.checkStack();
	a.push(9);
	a.checkStack();
	a.push(4);
	a.checkStack();
	a.push(7);
	a.pop();
	a.checkStack();
	a.pop();
	a.checkStack();
	a.pop();
	a.checkStack();
	a.pop();
	a.checkStack();

	return 0;
}