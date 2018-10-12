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

int ht(Node *root)
{
	Node *temp=new Node();
	queue<Node*> q;
	q.push(root);
	int h=0,c=0;
	while(1)
	{
		c=q.size();
		if(c==0)
		return h;
		else
		h++;
		while(c>0)
		{
			temp=q.front();
			if(temp->left)
			q.push(temp->left);
			if(temp->right)
			q.push(temp->right);
			q.pop();
			c--;
		}
		
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
	head->right->right->left=new Node(10);
	cout<<ht(head)-1;
	return 0;
}
