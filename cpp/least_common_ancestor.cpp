#include<bits/stdc++.h>
using namespace std;

struct node{
	int data;
	struct node*left;
	struct node*right;
};

struct node* insert(struct node*root,int k){
	if(root==NULL){
		struct node*temp=(struct node*)malloc(sizeof(struct node));
		temp->data=k;
		temp->left=NULL;
		temp->right=NULL;	
		return temp;	
	}
	
	if(root->data >= k){
		root->left=insert(root->left,k);
	}
	else {
		root->right=insert(root->right,k);
	}
	return root;
}

void inorder(struct node*root){
	if(root==NULL){
		return;
	}
	inorder(root->left);
	cout<<root->data;
	inorder(root->right);
}

struct node*lct(struct node*root,int p ,int r){
	if(root==NULL){
		return NULL;
	}
	if(root->data == p || root->data ==r){
		return root;
	}
	struct node *temp1 = lct(root->left,p,r);
	struct node *temp2 = lct(root->right,p,r);
	if(temp1!=NULL && temp2!=NULL){
		return root;
	}
	else{
		return(temp1?temp1:temp2);
	}
}

int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	struct node*root=NULL;
	for(int i=0;i<n;i++){
		root=insert(root,arr[i]);
	}		
	inorder(root);
	int p,r;
	cin>>p>>r;
	struct node* pp= lct(root,p,r);
	cout<<pp->data;
}
