#include<stdio.h>
#include<stdlib.h>


typedef struct tree{
    int n;
    struct tree *left;
    struct tree *right;
}node;

//bool delete(node *, int);
void postorder(node *);
void preorder(node *);
void inorder(node *);
int search(int, node *);
node *create(int );
int insert(int , node *);

int main()
{
    int num, choice;
    printf("Enter the root element: ");
    scanf("%d", &num);
    node *tree = create(num);
    if (tree == NULL)
    {
        return 1;
    }
    while (1)
    {
        printf("What do you want to do? 1. Insert. 2. Search 3. Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                printf("Enter no. to insert: ");
                scanf("%d", &num);
                insert(num, tree);
                break;
            case 2:
                printf("Enter no. to search: ");
                scanf("%d", &num);
                if (search(num, tree))
                    printf("Found %d in the tree.\n", num);
                else
                    printf("Not found\n");
                break;
            default:
                inorder(tree);
                printf("\n");
                preorder(tree);
                printf("\n");
                postorder(tree);
                printf("\n");
                return 0;
        }
    }
    return 0;
}
node *create(int num)
{
    node *new = (node *)malloc(sizeof(node *));
    if (new == NULL)
    {
        return NULL;
    }
    new->n = num;
    new->right = NULL;
    new->left = NULL;
    return new;
}
int insert(int num, node *tree)
{
    node *temp = tree;
    node *temp2= NULL;
    while(temp != NULL)
    {
        if (temp->n > num)
        {
            temp2 = temp;
            temp = temp->left;
        }
        else if (temp->n < num)
        {
            temp2 = temp;
            temp = temp->right;
        }
        else
            return 0;
    }
    if (temp2->n > num)
        temp2-> left = create(num);
    else if (temp2->n <num)
        temp2-> right = create(num);
    return 1;
}
int search(int num, node *tree)
{
    node *temp = tree;
    /*while(temp != NULL)
    {
        if (temp->n > num)
        {
            temp = temp->left;
        }
        else if (temp->n < num)
        {
            temp = temp->right;
        }
        else if (temp->n == num)
            return true;
    }*/
    if (temp->n == num)
    	return 1;
    else if (temp->n > num && temp->left != NULL)
    	return search(num, temp->left);
    else if (temp->n < num && temp->right != NULL)
    	return search(num, temp->right);
    return 0;
}
void inorder(node *tree)
{
	node *temp = tree;

	if (temp->left == NULL && temp->right == NULL)
	{
		printf("%d ", temp->n);
		return ;
	}
	else
	{
		if (temp->left != NULL)
			inorder(temp->left);
		printf("%d ", temp->n);
		if (temp->right != NULL)
			inorder(temp->right);
	}
	return ;
}
void preorder(node *tree)
{
	node *temp = tree;
	if (temp->left == NULL && temp->right == NULL)
	{
		printf("%d ", temp->n);
		return ;
	}
	else
	{
		printf("%d ", temp->n);
		if (temp->left != NULL)
			preorder(temp->left);
		if (temp->right != NULL)
			preorder(temp->right);
	}
	free(temp);
	return ;
}
void postorder(node *tree)
{
	node *temp = tree;
	if (temp->left == NULL && temp->right == NULL)
	{
		printf("%d ", temp->n);
		return ;
	}
	else
	{
		if (temp->left != NULL)
			postorder(temp->left);
		if (temp->right != NULL)
			postorder(temp->right);
		printf("%d ", temp->n);
	}
	free(temp);
	return ;
}
