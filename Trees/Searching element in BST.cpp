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


// Search Function
bool Search(BSTNode *root, int d)
{
	if(root==NULL)
		return 0;
		
	else if(root->data == d)
		return 1;
		
	else if(d < root->data )
		return Search(root->left , d);
		
	else 
		return Search(root->right,d);
		
				
}




int main()
{
	struct BSTNode *rootPtr = NULL;
	
	rootPtr = Insert(rootPtr , 5);
	rootPtr = Insert(rootPtr , 7);
	rootPtr = Insert(rootPtr , 4);
	rootPtr = Insert(rootPtr , 15);
	
	int element;
	cout<<"Enter number to search : ";
	cin>>element;
	
	int flag =Search(rootPtr,element);
	
	if(flag==1)
		cout<<"Found!";
	else 
	cout<<"Not Found!";
	
	
	
return 0;
}


