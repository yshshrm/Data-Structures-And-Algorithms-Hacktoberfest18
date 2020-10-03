#include "LinkedList.h"

LinkedList::LinkedList()
{
	head = NULL;
	tail = NULL;
}

bool LinkedList::isEmpty()
{
	return head == NULL;
}

void LinkedList::insertAfter(Node* y, int d)
{
	Node* n = new Node(d);
	n->next = y->next;
	n->prev = y;
	y->next = n;
	n->next->prev = n;
}

void LinkedList::remove(Node* x)
{
	if (x->prev == NULL)
	{
		head = x->next;
		x->next->prev = NULL;
	}
	else if (x->next == NULL)
	{
		tail = x->prev;
		x->prev->next = NULL;
	}
	else
	{
		x->prev->next = x->next;
		x->next->prev = x->prev;
	}
	delete x;
}

void LinkedList::print()
{
	Node* temp = head;
	while (temp != NULL)
	{
		cout << temp->data << ' ';
		temp = temp->next;
	}
	cout << '\n';
}

Node* LinkedList::getHead()
{
	return head;
}

void LinkedList::insertBefore(Node* y, int d)
{
	Node* n = new Node();
	y->prev->next = n;
	n->prev = y->prev;
	n->next = y;
	y->prev = n;
	n->data = d;
}

void LinkedList::insert(int d)
{
	Node* n = new Node(d);
	if (isEmpty())
	{
		head = n;
		tail = n;
	}
	else
	{
		n->prev = tail;
		n->next = NULL;
		n->prev->next = n;
		tail = n;
	}
}

void LinkedList::remove(int d)
{
	remove(search(d));
}

Node* LinkedList::search(int d)
{
	Node* t = head;
	while (t != NULL)
	{
		if (t->data == d)
		{
			return t;
		}
		t = t->next;
	}
	return nullptr;
}
