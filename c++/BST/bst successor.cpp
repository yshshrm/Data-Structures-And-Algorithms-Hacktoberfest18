//if right not null, the successor is leftmost node of  right subtree
//leftmost means the left branch fromt the root
//if right is null, use parent to move up to left broken branch(see geeksforgeeks)

#include <stdio.h>
#include <stdlib.h>

/* A binary tree node has data, pointer to left child
and a pointer to right child */
struct node
{
	int data;
	struct node* left;
	struct node* right;
	struct node* parent;
};

struct node * minValue(struct node* node); 

struct node * inOrderSuccessor(struct node *root, struct node *n)
{
// step 1 of the above algorithm 
if( n->right != NULL )
	return minValue(n->right);

// step 2 of the above algorithm
struct node *p = n->parent;
while(p != NULL && n == p->right)
{
	n = p;
	p = p->parent;
}
return p;
}

/* Given a non-empty binary search tree, return the minimum data 
	value found in that tree. Note that the entire tree does not need
	to be searched. */
struct node * minValue(struct node* node) {
struct node* current = node;

/* loop down to find the leftmost leaf */
while (current->left != NULL) {
	current = current->left;
}
return current;
}

/* Helper function that allocates a new node with the given data and 
	NULL left and right pointers. */
struct node* newNode(int data)
{
struct node* node = (struct node*)
					malloc(sizeof(struct node));
node->data = data;
node->left = NULL;
node->right = NULL;
node->parent = NULL;

return(node);
}

/* Give a binary search tree and a number, inserts a new node with 
	the given number in the correct place in the tree. Returns the new
	root pointer which the caller should then use (the standard trick to 
	avoid using reference parameters). */
struct node* insert(struct node* node, int data)
{
/* 1. If the tree is empty, return a new,
	single node */
if (node == NULL)
	return(newNode(data));
else
{
	struct node *temp; 

	/* 2. Otherwise, recur down the tree */
	if (data <= node->data)
	{ 
		temp = insert(node->left, data);
		node->left = temp;
		temp->parent= node;
	}
	else
	{
		temp = insert(node->right, data);
		node->right = temp;
		temp->parent = node;
	} 

	/* return the (unchanged) node pointer */
	return node;
}
} 

/* Driver program to test above functions*/
int main()
{
struct node* root = NULL, *temp, *succ, *min;

//creating the tree given in the above diagram
root=insert(root,15);
root=insert(root,6);
root=insert(root,18);
root=insert(root,3);
root=insert(root,7);
root=insert(root,17);
root=insert(root,20);
root=insert(root,2);
root=insert(root,4);
root=insert(root,13);
root=insert(root,9);
temp = root->left->right;

succ = inOrderSuccessor(root, temp);
if(succ != NULL)
	printf("\n Inorder Successor of %d is %d ", temp->data, succ->data); 
else
	printf("\n Inorder Successor doesn't exit");

getchar();
return 0;
}

