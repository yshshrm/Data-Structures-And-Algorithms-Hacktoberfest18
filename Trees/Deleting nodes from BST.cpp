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

BSTNode *FindMin(BSTNode *root)
{
	if(root==NULL)
	return NULL;	
	
	if(root->left==NULL)
	return root;
	 
	while(root->left!=NULL)
	{
		root=root->left;
	}
		
	return root;
	
}



struct BSTNode* Delete(BSTNode *root , int data)
{
	if(root==NULL)
		return root;
		
	else if(root->data < data)
		root->right=Delete(root->right,data);
	
	else if(root->data > data)
	root->left=Delete(root->left , data);
	
	else // if data matches
	{
		// case 1 : no child
		
		if(root->left==NULL && root->right==NULL )
		{
			delete root;
			root = NULL;
			return root;	
		}
		
		// case 2: 1 child
		else if(root->left == NULL)
		{
			BSTNode *temp =root;
			root = root->right;
			delete temp;
			return root;
			
		}
		else if (root->right == NULL)
		{
			BSTNode *temp =root;
			root = root->left;
			delete temp;
			return root;
			
		}
		
		//case 3 : two children
		else
		{
			BSTNode *temp = FindMin(root->right);
			root->data= temp->data;
			root->right= Delete(root->right , temp->data);
			
		}
	
	
	} 	
		
	return root;			
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


	rootPtr=Delete(rootPtr,15);
	
	
	
return 0;
}


