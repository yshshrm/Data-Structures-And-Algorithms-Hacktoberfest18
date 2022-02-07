#include <iostream>
using namespace std;

struct Node {
	int data;
	struct Node *left, *right;
};


Node* newNode(int data)
{
	Node* temp = new Node;
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

void printPostorder(struct Node* node)
{
	if (node == NULL)
		return;

	
	printPostorder(node->left);

	
	printPostorder(node->right);

	
	cout << node->data << " ";
}


void printInorder(struct Node* node)
{
	if (node == NULL)
		return;

	
	printInorder(node->left);

	
	cout << node->data << " ";

	
	printInorder(node->right);
}


void printPreorder(struct Node* node)
{
	if (node == NULL)
		return;

	
	cout << node->data << " ";

	
	printPreorder(node->left);


	printPreorder(node->right);
}


int main()
{
	struct Node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);

	cout << "\nPreorder traversal of binary tree is \n";
	printPreorder(root);

	cout << "\nInorder traversal of binary tree is \n";
	printInorder(root);

	cout << "\nPostorder traversal of binary tree is \n";
	printPostorder(root);

	return 0;
}
