#include <iostream>
#include <cstdlib>
using namespace std;

// define default capacity of stack
#define SIZE 10

// Class for stack
template <class X>
class stack
{
	X *arr;
	int top;
	int capacity;

public:
	stack(int size = SIZE);	// constructor

	void push(X);
	X pop();
	X peek();

	int size();
	bool isEmpty();
	bool isFull();

	// destructor
	~stack(){
		delete[] arr;
	}
};

// Constructor to initialize stack
template <class X>
stack<X>::stack(int size)
{
	arr = new X[size];
	capacity = size;
	top = -1;
}

// function to add an element x in the stack
template <class X>
void stack<X>::push(X x)
{
	if (isFull())
	{
		cout << "OverFlow\nProgram Terminated\n";
		exit(EXIT_FAILURE);
	}

	cout << "Inserting " << x << endl;
	arr[++top] = x;
}

// function to pop top element from the stack
template <class X>
X stack<X>::pop()
{
	// check for stack underflow
	if (isEmpty())
	{
		cout << "UnderFlow\nProgram Terminated\n";
		exit(EXIT_FAILURE);
	}

	cout << "Removing " << peek() << endl;

	// decrease stack size by 1 and (optionally) return the popped element
	return arr[top--];
}

// function to return top element in a stack
template <class X>
X stack<X>::peek()
{
	if (!isEmpty())
		return arr[top];
	else
		exit(EXIT_FAILURE);
}

// Utility function to return the size of the stack
template <class X>
int stack<X>::size()
{
	return top + 1;
}

// Utility function to check if the stack is empty or not
template <class X>
bool stack<X>::isEmpty()
{
	return top == -1;	// or return size() == 0;
}

// Utility function to check if the stack is full or not
template <class X>
bool stack<X>::isFull()
{
	return top == capacity - 1;	// or return size() == capacity;
}

int main()
{
	stack<string> pt(2);

	pt.push("A");
	pt.push("B");

	pt.pop();
	pt.pop();

	pt.push("C");

 	// Prints the top of the stack
 	cout << "Top element is: " << pt.peek() << endl;

	// Returns the number of elements present in the stack
	cout << "Stack size is " << pt.size() << endl;

	pt.pop();

	// check if stack is empty or not
	if (pt.isEmpty())
		cout << "Stack Is Empty\n";
	else
		cout << "Stack Is Not Empty\n";

	return 0;
}