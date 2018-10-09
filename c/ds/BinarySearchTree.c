#include<stdio.h>
#include<stdlib.h>


struct btnode {
	int info;
	struct btnode* r;
	struct btnode* l;
	};
	
typedef struct btnode BTNODE;

BTNODE* insert(BTNODE* root, int info){
	if(root==NULL){
		root=(BTNODE *)malloc(sizeof(BTNODE));
		root->info= info;
		root->l= NULL;
		root->r=NULL;
		return root;
		}
	 if(root->info<info){
	 	root->r= insert(root->r, info);
	 	return root;
	 	}
	 if(root->info>info){
	 	root->l= insert(root->l, info);
	 	return root;
	 	}
	 }

int check(BTNODE* root){
	int degree=0;
	if(root->r!=NULL)
		degree++;
	if(root->l!=NULL)
		degree++;
	return degree;
	}
		 
	 
BTNODE* delete(BTNODE* root, int info){
	if(root==NULL){
		printf("Element not present");
		return root;
		}
	if(root->info==info){
		int degree = check(root);
		if(degree==0){
			free(root);
			return NULL;
			}
		if(degree==1){
			if(root->r!=NULL){
				BTNODE *temp =root;
				root= root->r;
				free(temp);
				return root;
				}
			else{
				BTNODE *temp =root;
				root= root->l;
				free(temp);
				return root;
				}
			}
		if(degree==2){
				BTNODE *next = root->r;
				while(next->l!=NULL){
					next=next->l;
					}
				root->info= next->info;
				root->r= delete(root->r, next->info);
				return root;
				}
		}
	if(root->info>info){
		root->l= delete(root->l, info);
		return root;
		}
	if(root->info<info){
		root->r= delete(root->r, info);
		return root;
		}
	}


BTNODE* preorder(BTNODE* root){
	if(root!=NULL){
		printf(" %d ", root->info);
	}
	if(root->l!=NULL){
		preorder(root->l);
		}
	if(root->r!=NULL){
		preorder(root->r);
		}
	return root;
}

BTNODE* inorder(BTNODE* root){
	
	if(root->l!=NULL){
		inorder(root->l);
		}
	if(root!=NULL){
		printf(" %d ", root->info);
	}
	if(root->r!=NULL){
		inorder(root->r);
		}
	return root;
}

BTNODE* postorder(BTNODE* root){
	if(root->l!=NULL){
		postorder(root->l);
		}

	if(root->r!=NULL){
		postorder(root->r);
		}
	if(root!=NULL){
		printf(" %d ", root->info);
	}
	return root;
}

void main(){
	BTNODE* root =NULL;
	int c, val;
	do{
		printf("1. add to Tree\n");
		printf("2. Delete from Tree\n");
		printf("3. Display Preorder\n");
		printf("4. Display Inordor\n");
		printf("5. Display Postorder\n");
		printf("6. Exit\n");
		printf("Choice : ");
		scanf("%d", &c);
		switch(c){
			case 1:
				printf("Value to insert: ");
				scanf("%d", &val);
				root= insert(root,val);
				break;
			case 2:
				printf("Value to Delete: ");
				scanf("%d", &val);
				root= delete(root,val);
				break;
			case 3:
				root= preorder(root);
				break;
			case 4:
				root= inorder(root);
				break;
			case 5:
				root= postorder(root);
				break;
			case 6:
				break;
			default:
				printf("Enter valid number\n");
			}
		}
	while(c!=6);
	}
	

		
	
