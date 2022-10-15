#include<iostream>
#include<string>
#include<queue>
using namespace std;

struct BSTNode
{
	int data;
	BSTNode *left;
	BSTNode *right;
	
};

struct BSTNode *GetNewNode(int data)
{
	struct BSTNode *NewNode = new BSTNode();
	NewNode->data=data;
	NewNode->left = NULL ; 
	NewNode->right = NULL;
	
	return NewNode;
}

struct BSTNode *Insert(BSTNode* root, int data)
{
	if(root==NULL)
		root= GetNewNode(data);
	
	else if(data <= root->data)
		root->left = Insert(root->left , data);
		
	else
		root->right = Insert(root->right , data);
	
	return root;
}

bool IsSubtreeLesser(BSTNode *root , int d)
{
	if(root==NULL)
		return 1;
		
	else if(root->data<=d && IsSubtreeLesser(root->left , d) &&IsSubtreeLesser(root->right , d))
		return 1;
	
	else 
		return 0;
	
}

bool IsSubtreeGreater(BSTNode *root , int d)
{
	if(root==NULL)
		return 1;
		
	else if(root->data >d && IsSubtreeGreater(root->left , d) &&IsSubtreeGreater(root->right , d))
		return 1;
	
	else 
		return 0;
	
}


bool IsBST(BSTNode *root)
{
	if(root==NULL)
		return 1;
		
	else if(IsSubtreeLesser(root->left , root->data) && IsSubtreeGreater(root->right,root->data) && IsBST(root->left) && IsBST(root->right))	
	return 1;
	
	else 
	return 0;
	
	
	
}


int main()
{
	struct BSTNode *rootPtr = NULL;
	
	rootPtr = Insert(rootPtr , 5);
	rootPtr = Insert(rootPtr , 7);
	rootPtr = Insert(rootPtr , 4);
	rootPtr = Insert(rootPtr , 15);
	rootPtr = Insert(rootPtr , 17);
	rootPtr = Insert(rootPtr , 14);
	rootPtr = Insert(rootPtr , 11);	
	
	if(IsBST(rootPtr))
		cout<<"Tree is BST.";
	else
		cout<<"Tree is not BST.";
	


	
return 0;
}


