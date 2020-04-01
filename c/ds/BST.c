#include<stdio.h>
#include<stdlib.h>
struct node
{
	int info;
	struct node *left;
	struct node *right;
};
typedef struct node Node;
void addNode(Node*,int);
Node* search(Node*,int);
void preorder(Node*);
void inorder(Node*);
void postorder(Node*);
void addNode(Node *root,int val)
{
	if(val<root->info)
	{
		if(root->left==NULL)
		{
			Node *newnode=(Node *)malloc(sizeof(Node));
			newnode->left=NULL;
			newnode->right=NULL;
			newnode->info=val;
			root->left=newnode;
			return;
		}
		else
		{
			addNode(root->left,val);
			return;
		}
	}
	else
	{
		if(root->right==NULL)
		{
			Node *newnode=(Node *)malloc(sizeof(Node));
			newnode->left=NULL;
			newnode->right=NULL;
			newnode->info=val;
			root->right=newnode;
			return;
		}
		else
		{
			addNode(root->right,val);
			return;
		}			
	}
}
Node* search(Node *root,int val)
{
	if(root==NULL)
		return NULL;
	else if(val==root->info)
		return root;
	else if(val<root->info)
		return search(root->left,val);
	else if(val>root->info)
		return search(root->right,val);
}						
void preorder(Node *root)
{
	if(root!=NULL)
	{
		printf("%d ",root->info);
		preorder(root->left);
		preorder(root->right);
	}
}
void inorder(Node *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		printf("%d ",root->info);
		inorder(root->right);
	}
}
void postorder(Node *root)
{
	if(root!=NULL)
	{
		postorder(root->left);
		postorder(root->right);
		printf("%d ",root->info);
	}
}				
void main()
{
	Node *retval;
	Node *root=(Node *)malloc(sizeof(Node));
	root->left=NULL;
	root->right=NULL;
	printf("Enter root value\n");
	scanf("%d",&root->info);
	int loop=1,choice,val;
	while(loop==1)
	{
		printf("Enter 1 to add nodes\nEnter 2 to search value\nEnter 3 to exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:printf("Enter value to add\n");
				scanf("%d",&val);
				addNode(root,val);
				break;
			case 2:printf("Enter value to search\n");
				scanf("%d",&val);
				retval=search(root,val);
			 	if(retval==NULL)
			 		printf("Value not found\n");
			 	else
			 		printf("Value found at %p\n",retval);	
				break;
			case 3:loop=0;
				break;
			default:printf("Wrong choice\n");
		}
	}
	preorder(root);
	printf("\n");
	inorder(root);
	printf("\n");
	postorder(root);
	printf("\n");
}						
