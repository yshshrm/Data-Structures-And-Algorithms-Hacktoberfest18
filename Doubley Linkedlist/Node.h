#pragma once
#include <iostream>
using namespace std;

class LinkedList;
class Node
{
	friend class LinkedList;
	int data;
	Node* next;
	Node* prev;
public:
	Node(int d = 0, Node* p = NULL, Node* n = NULL);
};
