#include "Node.h"

Node::Node(int d, Node* p, Node* n)
{
	data = d;
	prev = p;
	next = n;
}
