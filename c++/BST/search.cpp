#include<bits/stdc++.h>
using namespace std;
int c=0;
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

int search(Node *node,int k)
{
	if(node==NULL)
	return 0;
	if(k==node->data)
	return 1;
	if(k>node->data)
	search(node->right,k);
	else if(k<node->data)
	search(node->left,k);
}

Node *search1(Node *node,int k)
{
	if(node==NULL)
	return node;
	if(k==node->data)
	return node;
	if(k>node->data)
	search1(node->right,k);
	else if(k<node->data)
	search1(node->left,k);
}
int main()
{
	int k=0;
	Node *head=new Node(7);
	head->left=new Node(3);
	head->left->left=new Node(1);
	head->left->right=new Node(5);
	head->right=new Node(10);
	cout<<"Enter number:";
	cin>>k;
	(search(head,k)==1)?cout<<"Found":cout<<"Not Found";
//	Node *temp=search1(head,k);
//	cout<<temp->data+1;
//bfs(head);
	return 0;
}
