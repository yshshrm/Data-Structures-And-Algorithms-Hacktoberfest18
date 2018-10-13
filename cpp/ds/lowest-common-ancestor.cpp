#include <iostream>
using namespace std;

struct node
{
	int data;
	node* left;
	node* right;
	
};

node* newNode(int data)
{
	node* newnode  = new node;

	newnode->data = data;
	newnode->left = NULL;
	newnode->right = NULL;

	return(newnode);
}

//     sample inorder tree
//                 25        //root
//		  /    \
//		 15      35
//		/ \     / 
//	      10  20  30


node* inorderRoot()
{
	node* root = newNode(25);
	root->left = newNode(15);
	root->right = newNode(35);
	root->left->left = newNode(10);
	root->left->right = newNode(20);
	root->right->left = newNode(30);
	return root;
} 

//     sample binary tree
//		    3        //root
//		  /    \
//		 6      8
//		/ \      \
//	       2   11     13
//               /  \    /
//              9    5  7 


node* binaryTree()
{
	node* root = newNode(3);
	root->left = newNode(6);
	root->right = newNode(8);
	root->left->left = newNode(2);
	root->left->right = newNode(11);
	root->left->right->left = newNode(9);
	root->left->right->right = newNode(5);
	root->right->right = newNode(13);
	root->right->right->left = newNode(7);
	return root;
}

 //lcaBst() returns ancestor of only Binary search tree between n1 and n2
  // while lca() returns ancestor of any binary tree between n1 and n2.

node* lcaBST(node* root, int n1, int n2)
{
	if(root->data > max(n1,n2))
		lcaBST(root->left,n1,n2);

	else if(root->data < min(n1,n2))
		lcaBST(root->right,n1,n2);

	else
		return root;
}

node* lca(node* root, int a, int b)
{
	if(!root)
		return NULL;

	// if data of node is equal to any one 
	// of a or b
	if(root->data == a || root->data == b)
		return root;

	node* lnode = lca(root->left,a,b);
	node* rnode = lca(root->right,a,b);

//  if both lnode and rnode have value
	if(lnode && rnode)
		return root;
	else                 // if only one of them is
						 // null
		if(lnode)        // if lnode is not null
			return lnode;
		else			 // rnode may have val 
						 // otherwise null
			return rnode; 
}

int main()
{
	node* root = inorderRoot();
	node* a = lcaBST(root,10,35);
	cout<<a->data<<endl;

	root = binaryTree();
	a = lca(root,8,7);
	cout<<a->data<<endl;
 	return 0;
}
