#include<bits/stdc++.h>
using namespace std;

class Node
{
	public:
	Node *left;
	Node *right;
	int data;
	Node(int k)
	{
		this->data=k;
		left=NULL;
		right=NULL;
	}
	Node()
	{
	}
};


int bfs(Node *head)
{
	queue<Node*> q;
	Node *temp=head;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		if(temp->left)
		q.push(temp->left);
		if(temp->right)
		q.push(temp->right);
		temp=q.front();
		q.pop();
	}
}

int main()
{
	Node *head=new Node(1);
	head->left=new Node(2);
	head->right=new Node(3);
	head->left->left=new Node(4);
	head->left->right=new Node(5);
	head->right->right=new Node(6);
	bfs(head);
	return 0;
}
