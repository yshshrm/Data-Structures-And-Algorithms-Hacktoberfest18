#include <iostream>

using namespace std;

//NODE
struct node
{
	int data;
	node *left;
	node *right;
	node *parent;
};


node *root=NULL, *ptr;

//INSERT
node* insert(node *root, int key){

	if(root==NULL){
		ptr = new node;
		ptr->data = key;
		ptr->left=NULL;
		ptr->right=NULL;
		ptr->parent=NULL;
		root= ptr;
		return root;
	}
	else if(key<=root->data){
		root->left = insert(root->left, key);
		root->parent = root;
	}else if(key>root->data){
		root->right = insert(root->right, key);
		root->parent=root;
	}
	return root;
}

//INORDER TRAERSAL
void inorder(node *root){

	if(root==NULL){
		return;
	}
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}

//PRE ORDER TRAVERSAL
void preorder(node *root){

	if(root==NULL){
		return;
	}
	cout<<root->data<<" ";
	inorder(root->left);
	inorder(root->right);
}

//POST ORDER TRAVERSAL
void postorder(node *root){

	if(root==NULL){
		return;
	}
	inorder(root->left);
	inorder(root->right);
	cout<<root->data<<" ";
}

//SEARCH
node* search(node *root, int key){

	if(root==NULL){
		return root;
	}
	if(root->data==key){
		return root;
	}
	return search(root->left, key);
	return search(root->right, key);
}

//FIND MIN NODE
node* FindMin(node* root){
	if(root==NULL){
		return root;
	}
	if(root->left==NULL){
		return root;
	}
	return FindMin(root->left);
}

//FINDMAX NODE
node* FindMax(node* root){
	if(root==NULL){
		return root;
	}
	if(root->right==NULL){
		return root;
	}
	return FindMin(root->right);
}

//DELETE A NODE
node* dele(node *root, int key){
	if(root==NULL){
		return root;
	}
	else if(key<root->data){
		root->left = dele(root->left, key);
	}else if (key>root->data){
		root->right = dele(root->right, key);
	}else{

		//NO CHILD
		if(root->left==NULL && root->right==NULL){
			delete root;
			root=NULL;
		}

		//ONE CHILD
		else if(root->left==NULL){
			node *temp = root;
			root=root->right;
			delete temp;
		}
		else if(root->right==NULL){
			node *temp = root;
			root=root->left;
			delete temp;
		}

		//TWO CHILD
		else{
			node *temp  = FindMin(root->right);
			root->data = temp->data;
			root->right= dele(root->right, temp->data);
		}
	}

	return root;
}



int main(){

	//CREATE A TREE

	root = insert(root,50);

	insert(root,23);

	insert(root,18);

	insert(root,25);

	insert(root, 60);

	insert(root, 67);

	//INORDER TRAVERSE

	inorder(root);

	//SEARCH FOR A DATA

	cout<<"\n\n"<<search(root,23)->data;

	//DELETE A DATA
	dele(root, 23);

	cout<<"\n\n";

	inorder(root);

	return 0;
}
