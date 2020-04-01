// C++ program for Morris Preorder traversal 
#include <bits/stdc++.h> 
using namespace std; 

class node 
{ 
	public: 
	int data; 
	node *left, *right; 
}; 

/* Helper function that allocates a new node with the 
given data and NULL left and right pointers. */
node* newNode(int data) 
{ 
	node* temp = new node(); 
	temp->data = data; 
	temp->left = temp->right = NULL; 
	return temp; 
} 

// Preorder traversal without recursion and without stack 
void morrisTraversalPreorder(node* root) 
{ 
	while (root) 
	{ 
		// If left child is null, print the current node data. Move to 
		// right child. 
		if (root->left == NULL) 
		{ 
			cout<<root->data<<" "; 
			root = root->right; 
		} 
		else
		{ 
			// Find inorder predecessor 
			node* current = root->left; 
			while (current->right && current->right != root) 
				current = current->right; 

			// If the right child of inorder predecessor already points to 
			// this node 
			if (current->right == root) 
			{ 
				current->right = NULL; 
				root = root->right; 
			} 

			// If right child doesn't point to this node, then print this 
			// node and make right child point to this node 
			else
			{ 
				cout<<root->data<<" "; 
				current->right = root; 
				root = root->left; 
			} 
		} 
	} 
} 

// Function for sStandard preorder traversal 
void preorder(node* root) 
{ 
	if (root) 
	{ 
		cout<<root->data<<" "; 
		preorder(root->left); 
		preorder(root->right); 
	} 
} 

/* Driver program to test above functions*/
int main() 
{ 
	node* root = NULL; 

	root = newNode(1); 
	root->left = newNode(2); 
	root->right = newNode(3); 

	root->left->left = newNode(4); 
	root->left->right = newNode(5); 

	root->right->left = newNode(6); 
	root->right->right = newNode(7); 

	root->left->left->left = newNode(8); 
	root->left->left->right = newNode(9); 

	root->left->right->left = newNode(10); 
	root->left->right->right = newNode(11); 

	morrisTraversalPreorder(root); 

	cout<<endl; 
	preorder(root); 

	return 0; 
} 
