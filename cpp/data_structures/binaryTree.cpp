#include <bits/stdc++.h>
using namespace std;

struct node{
	int data;
	node* right;
	node* left;
};

node* newnode(int data)
{
	node* node = new node;
	node -> data = data;
	node-> left = NULL;
	node -> right = NULL;
	return node;	
}
void height(node* root)
{
	if(root == NULL)
	   return 0;
	else
	{
	 int lheight = height(root->left);
	 int rheight = height(root-> right);
	 if(lheight > rheight)
	    return (lheight+1);
	 else 
	   return (rheight+1);
	}
}

int main()
{
	struct node* root = newnode(1);
	root-> left = newnode(2);
	root-> right = newnode(3);
	root -> left->left = newnode(4);
	getchar();
	return 0;
}

