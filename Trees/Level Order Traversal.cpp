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


// Level Order
void LevelOrder(BSTNode *root)
{
	queue<BSTNode*> Q ;
	Q.push(root);
	
	while(!Q.empty())
	{
		BSTNode *ptr = Q.front();
	
		cout<<ptr->data<<"  ";
	
		if(ptr->left!=NULL)
			Q.push(ptr->left);
		
		if(ptr->right!=NULL)
			Q.push(ptr->right);
			
		Q.pop();
	}
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
	
	cout<<"Level Order Traversal : ";
	LevelOrder(rootPtr);
	
	
	
return 0;
}


