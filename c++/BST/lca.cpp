#include<bits/stdc++.h>
using namespace std;

class node
{
	public:
	int data;
	node *left;
	node *right;
	node(int k)
	{
		data=k;
		left=right=NULL;
	}
};

int lca(node *head,int v1,int v2)
{
	if(head->data>max(v1,v2))	
	lca(head->left,v1,v2);
	else if(head->data<min(v1,v2))
	lca(head->right,v1,v2);
	else
	return head->data;
}

int main()
{
	node *head=NULL;
	head=new node(5);
	head->left=new node(3);
	head->left->left=new node(2);
	head->right=new node(8);
	head->right->left=new node(6);
	head->right->left->right=new node(7);
	cout<<lca(head,3,8)<<endl;
	cout<<lca(head,8,3)<<endl;
	cout<<lca(head,2,4)<<endl;
	cout<<lca(head,4,6)<<endl;
	cout<<lca(head,8,2)<<endl;
	cout<<lca(head,6,7)<<endl;
	return 0;
}
