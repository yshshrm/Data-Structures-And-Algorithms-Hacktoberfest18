#include<iostream>
#include<string>
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



int Min(BSTNode *root)
{
	if(root==NULL)
		return -1;
		
	else if(root->left == NULL)
		return root->data;	
		
	else
		return Min(root->left);
	
}

int Max(BSTNode *root)
{
	if(root==NULL)
		return -1;
		
	else if(root->right == NULL)
		return root->data;	
		
	else
		return Max(root->right);

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
	
	cout<<"Minimum value = "<<Min(rootPtr)<<endl;
	cout<<"Maximum value = "<<Max(rootPtr)<<endl;
	
	
	
	
	
	
return 0;
}


