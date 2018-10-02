#include <iostream>
#include <stdexcept>

template <typename T>
struct Item
{
public:
	T value;
	Item *next;
};

template <typename T>
class Stack
{
private:
	Item<T> *items = nullptr;
public:
	void push(const T &item)
	{
		auto itm = new Item<T>();
		itm->value = item;
		itm->next = items;
		items = itm;
	}
	
	T pop()
	{	
		if(this->items != nullptr)
		{
			T value;
			auto item = this->items;
			value = item->value;
			this->items = item->next;
			delete item;
			return value;
		}
		throw std::out_of_range("Empty stack");
	}

	bool isEmpty()
	{
		return this->items == nullptr;
	}
};

int main()
{
	Stack<int> stack;
	stack.push(223);
	stack.push(15);
	stack.push(3);
	stack.push(2);
	stack.push(1);

	while(!stack.isEmpty())
		std::cout<<stack.pop()<<std::endl;

	Stack<std::string> strStack;
	strStack.push("world!");
	strStack.push("Hello ");

	std::cout<<strStack.pop();
	std::cout<<strStack.pop()<<std::endl;
}
