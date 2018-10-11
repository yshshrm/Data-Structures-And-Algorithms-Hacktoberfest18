#include <iostream>
#include <string>

template <typename T>
class List
{
	class Node
	{
	private:
		Node * next;
		Node* prev;
		T data;

	public:
		Node(T datain)
		{
			next = nullptr;
			prev = nullptr;
			data = datain;
		}
		void Show()
		{
			std::cout << "Data: " << data << ", next: " << next << ", previous: " << prev << std::endl;
		}

		friend class List;
	};

private:
	Node * first;
	Node* last;
	int size;

public:
	List()
	{
		first = nullptr;
		last = nullptr;
		size = 0;
	}

	void AddFirst(T datain)
	{
		Node* n = new Node(datain);
		if (first == nullptr)
		{
			first = n;
			last = n;
			size++;
		}
		else
		{
			first->prev = n;
			n->next = first;
			first = n;
			size++;
		}
	}

	void PrintList()
	{
		Node* iter = first;

		while (iter)
		{
			iter->Show();
			iter = iter->next;
		}
	}

	Node* Begin()
	{
		return first;
	}
};





int main()
{
	List<int> l1;
	l1.AddFirst(1);
	l1.AddFirst(5);
	l1.AddFirst(10);



	l1.PrintList();



	system("PAUSE");
}