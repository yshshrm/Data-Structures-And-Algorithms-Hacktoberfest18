#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


#define TRUE 1
#define FALSE 0

//structrure for each node in a tree
struct node
{
	int data;
	struct node *right;
	struct node *left;
	bool Rthread;
};


struct node *root=NULL;			//root of the tree


//function to create new node
struct node* create_node(int key)
{
	struct node* temp=(struct node*)malloc(sizeof(struct node));


	temp->data=key;
	temp->right=NULL;
	temp->left=NULL;
	temp->Rthread=FALSE;

	return temp;
}



//search function which returns the node with key
struct node* search(struct node *curr,int key)
{
	struct node* temp=curr;		//temporary pointer

	//if temp->data = key  then temp is reqd. node
	if(temp->data==key)
		return temp;


	temp=search(curr->left,key);		//search left sub tree of curr

	//return if key found
	if(temp!=NULL)
		return temp;


	temp=search(curr->right,key);		//search right sub tree of curr

	//return if key found
	if(temp!=NULL)
		return temp;					


	return NULL;				//returning NULL if key not found
}

void insert(int key,int parent,char S)
{
	struct node* temp = create_node(key);		//creating temporary node
	//if root is NULL make temp as root
	if(root==NULL)
	{
		root=temp;
		return;
	}

	struct node* Prent=search(root,parent);		//search for the parent node

	//if parent node not found
	if(Prent==NULL)
	{
		printf("parent not found\n");
		return;
	}

	//insert to left of parent
	if(S=='L')
	{
		if(Prent->left==NULL)
		{
			Prent->left=temp;
		}
		else
			printf("%d is already present at the specified position for %d\n",Prent->left->data,key);
	}

	//insert to right of parent
	else if(S=='R')
	{
		if(Prent->right==NULL)
		{
			Prent->right=temp;
		}
		else
			printf("%d is already present at the specified position for %d\n",Prent->right->data,key);
	}

}

//print in order reccurcively
void inorder(struct node *curr)
{
	if(curr==NULL)
		return;

	inorder(curr->left);

	printf("%d ",curr->data);

	inorder(curr->right);

}

//calculating height of tree
int height(struct node* curr)
{
	//if no node is present height is -1
	if(curr==NULL)
		return -1;
	

	int lh=height(curr->left)+1;		//finding height of left sub tree
	int rh=height(curr->right)+1;		//finding height of right sub tree


	//returning the max. value among left and right sub trees
	if(lh>rh)
		return lh;
	return rh;
}

//finding inorder succesor of child node
/*struct node* inordersucc(struct node *child)
{

}*/

//creating threads to binary tree created
void createThread(struct node *curr)
{
	/*//if right child is null and left is not
	if(curr->right==NULL&&curr->left!=NULL)
	{
		curr->right=inordersucc(curr);		//connect right pointer to inorder succesor
		curr->Rthread=TRUE;					//making its thread TRUE

		createThread(curr->left);			//creating threads for its left subtree
	}

	//if right child and left child are not NULL
	else if(curr->right!=NULL&&curr->left!=NULL)
	{
			createThread(curr->left);		//creating threads for left subtree
			createThread(curr->right);		//creating threads for right subtree
	}

	//if right child and left child are NULL
	else if(curr->right==NULL&&curr->left==NULL)
	{
		curr->right=inordersucc(curr);		//connect right pointer to inorder succesor
		curr->Rthread=TRUE;					//making its thread TRUE
	}*/

}

//inorder travesal for threaded binary tree
void Threadinorder(struct node *curr)
{
	//if current node is NULL
	if(curr==NULL)
		return;

	Threadinorder(curr->left);		//recursively call left sub tree

	//printing key if Rthread is TRUE
	if(curr->Rthread==TRUE)
		printf("%dT ",curr->data);

	//printing key if Rthread is FALSE
	else
		printf("%d ",curr->data);

	//calling right subtree if there is no thread
	if(curr->Rthread==FALSE)
	{
		Threadinorder(curr->right);
	}
	//stopping recursive call if there is thread
	else if(curr->Rthread==TRUE)
		Threadinorder(NULL);
}

int main()
{
	int key;
	int P;
	char S;
	int N;

	scanf("%d",&N);		//taking input for no. of nodes

	//taking Node inputs and insertion details
	for (int i = 0; i < N; ++i)
	{
		scanf("%d %d %c",&key,&P,&S);
		insert(key,P,S);
	}
	
	//printing in order
	inorder(root);
	printf("\n");

	//calculating height and printing it
	int h=height(root);
	printf("%d\n",h );

	//creating threads for binary tree
	createThread(root);

	//inorder for threaded binary tree
	Threadinorder(root);
	printf("\n");
}