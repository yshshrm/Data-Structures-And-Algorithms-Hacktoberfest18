#include<stdio.h>

struct node{	
	int number;
	struct node *leftChild;
	struct node *rightChild;
};

void add(int child);
struct node *find(struct node *temp);
void printPreorder(struct node *root);
void printPostorder(struct node *temp);
void printInorder(struct node *temp);
int parent, child;
             

struct node *root = NULL, *found, *temporaryNode, *newNode, *temp;

int main(int argc, char const *argv[]){
	int choice;
	while(1){
		printf("1.Add node.\n2.Display\n");
		printf("Enter choice: ");
		scanf("%d", &choice);
		switch(choice){
			case 1:	printf("Enter child node: ");
					scanf("%d", &child);
					add(child);
					break;

			case 2:	printf("Postorder : ");
					printPostorder(root);
					printf("Preorder : ");
					printPreorder(root);
					printf("Inorder : ");
					printInorder(root);
					printf("\n");
					break;
			case 3: exit(0);
		}
	}
	/* code */
	return 0;
}

void add(int child){
	int choice;
	newNode = (struct node *)malloc(sizeof(struct node));
	newNode -> rightChild = NULL;
	newNode -> leftChild = NULL;
	newNode -> number = child;
	if(root == NULL){
		root = newNode;
	}
	else{
		printf("Enter Parent Node: ");
		scanf("%d", &parent);
		temp = find(root);
		temp = found;
		printf("%d",temp->number);		
		printf("1.Add left side.\n2.Add right side.\n");
		printf("Which side do you want to add the node: ");
		scanf("%d", &choice);
		switch(choice){
			case 1: temp -> leftChild = newNode;
					break;
			case 2: temp -> rightChild = newNode;
					break;
		}
	}
}

//Error found here

struct node *find(struct node *temp){
	printf("root element = %d\n", temp -> number);
	if(temp -> number == parent){
		// printf("Entered if condition...");
		found = temp;
		return temp;
	}
	// if(temp == NULL)
	// 	return NULL;
	// if(temp == NULL)
	// 	return ;
	if(temp -> leftChild != NULL)
		find(temp -> leftChild);
	if(temp -> rightChild != NULL)	
		find(temp -> rightChild);
}

void printPreorder(struct node *root){
	// preorder
	if(root == NULL)
		return;
	printf("%d ", root -> number);
	printPreorder(root -> leftChild);	
	printPreorder(root -> rightChild);
}


void printPostorder(struct node *root){
	// postorder
	if(root == NULL)
		return;
	printPostorder(root -> leftChild);	
	printPostorder(root -> rightChild);
	printf("%d ", root -> number);
}

void printInorder(struct node *root){
	// Inorder
	if(root == NULL)
		return;
	printInorder(root -> leftChild);	
	printf("%d ", root -> number);
	printInorder(root -> rightChild);
	
}
