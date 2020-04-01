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

void inorder(struct Node* node)
{
    if (node == NULL)
        return;
    inorder(node->left);
    cout << node->data << " ";
    inorder(node->right);
}

int max(Node *root)
{
	if(root->left==NULL)
	return root->data;
	max(root->left);
}

int min(Node *root)
{
	if(root->right==NULL)
	return root->data;
	min(root->right);
}

int main()
{
	int k=0;
	Node *head=new Node(7);
	head->left=new Node(3);
	head->left->left=new Node(1);
	head->left->right=new Node(5);
	head->right=new Node(10);
	head->right->left=new Node(8);
	inorder(head);
	cout<<"\nMaximum Element:"<<max(head)<<"\nMinimum Element:"<<min(head);
	return 0;
}
