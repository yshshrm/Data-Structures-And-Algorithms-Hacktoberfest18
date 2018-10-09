//Program to Generate Binary Tree from given Traversal Schemes

#include<stdio.h>
#include<stdlib.h>


struct btnode {
	int info;
	struct btnode* r;
	struct btnode* l;
	};
	
typedef struct btnode BTNODE;

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

int search(int root, int check, int in[]){
	int i=0;
	while(in[i]!=root){
		i++;
		}
	int j=i;
	while(j!=0 && in[j]!=check){
		j--;
		}
	if(in[j]==check){
		return 0;
		}
	else return 1;
	}
	
BTNODE* insert(BTNODE* root, int info, int in[]){
	if(root==NULL){
		root=(BTNODE *)malloc(sizeof(BTNODE));
		root->info= info;
		root->l= NULL;
		root->r=NULL;
		return root;
		}
	if(search(root->info, info, in)== 0){
		printf("%d\n", root->info);
		root->l =insert(root->l, info, in);
		return root;
		}
	if(search(root->info, info, in)== 1){
		root->r =insert(root->r, info, in);
		return root;
		}
	}
	

BTNODE* buildPre(BTNODE* root, int in[], int o[], int val){
	int i=0;
	while(i!=val){
		root= insert(root, o[i], in);
		i++;
		inorder(root);
		printf("\n");
		}
	return root;
	}


BTNODE* buildPost(BTNODE* root, int in[], int o[], int val){
	int i=val-1;
	printf("Inside Build\n");
	while(i!=-1){
		root= insert(root, o[i], in);
		i--;
		inorder(root);
		printf("\n");
		}
	return root;
	}
	

void main(){
	BTNODE* root =NULL;
	int c,val, i;
	do{
		printf("1. Build tree using postorder\n");
		printf("2. Build tree using preorder\n");
		printf("6. Exit\n");
		printf("Choice : ");
		scanf("%d", &c);
		printf("Enter number of nodes in tree");
		scanf("%d", &val);
		int in[val], o[val];
		switch(c){
			case 1:
				printf("Enter the inorder traversal");
				for(i=0; i<val; i++){
					scanf("%d", &in[i]);
				}
				printf("Enter the postorder traversal");
				for(i=0; i<val; i++){
					scanf("%d", &o[i]);
				}
				root= buildPost(root, in, o, val);
				inorder(root);
				
				break;
			case 2:
				printf("Enter the inorder traversal");
				for(i=0; i<val; i++){
					scanf("%d", &in[i]);
				}
				printf("Enter the preorder traversal");
				for(i=0; i<val; i++){
					scanf("%d", &o[i]);
				}
				printf("\n");
				root= buildPre(root, in, o, val);
				break;
			case 6:
				break;
			default:
				printf("Enter valid number\n");
			}
		}
	while(c!=6);
	}
