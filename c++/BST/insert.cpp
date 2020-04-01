#include<bits/stdc++.h>
using namespace std;

class Node
{
	public:
		int data;
		Node *left;
		Node *right;
		Node(int k)
		{
			data=k;
			left=right=NULL;
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
Node *newn(int k)
{
	Node *temp=new Node(k);
	return temp;
}

Node *insert(Node *root,int k)
{
	if(root==NULL)return newn(k);

	if(root->data<k)
		root->right=insert(root->right,k);
	else if(root->data>k)
		root->left=insert(root->left,k);
	return root;
}

int main()
{
	Node *root=NULL;
	root=insert(root,5);
	root=insert(root,4);
	root=insert(root,7);
	root=insert(root,2);
	root=insert(root,6);
	root=insert(root,1);
	root=insert(root,3);
	bfs(root);
	return 0;
}
