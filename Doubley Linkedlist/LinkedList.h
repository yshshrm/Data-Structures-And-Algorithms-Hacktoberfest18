#pragma once
#include "Node.h"

class LinkedList
{
	Node* head;
	Node* tail;
public:
	LinkedList();
	bool isEmpty();
	void insertAfter(Node* y, int d);  //inserts after a node y
	void remove(Node* x);  //removes a node x
	void print();
	Node* getHead();  //for testing purpose
	void insertBefore(Node* y, int d);   /*inserts a node before node y*/

	//Make following functions for ordered linked list
	void insert(int d);
	void remove(int d);
	Node* search(int d);
	void sortInsert(int d);
	//void Merge(LinkedList L);  /*Nodes from LinkedList L are merged into node in this LinkedList, maintaining the order */
	//~LinkedList();  //destructor
};
