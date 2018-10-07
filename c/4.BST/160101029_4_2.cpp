#include<iostream>
#include<vector>			

using namespace std;

/*Tree node definiton*/
struct TreeNode{
	int data;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x){
		data=x;
		left=right=NULL;
	}
};
int preorder_index=0;
TreeNode* buildTree(int preorder[],int indexOfinorder[],int start,int end){
	if(start<=end){
		TreeNode *node = new TreeNode(preorder[preorder_index]);
		int inorder_index = indexOfinorder[preorder_index]/*TODO*/ ;
		preorder_index++;
		node->left = buildTree(preorder,indexOfinorder,0,inorder_index);/*TODO*/;
		node->right = buildTree(preorder,indexOfinorder,inorder_index,end);/*TODO*/;
		return node/*TODO*/;
	}
	else
		return NULL/*TODO*/;
}

void print_preorder(TreeNode *root){
	/*TODO*/
	if(root==NULL)
		return;
	cout<<root->data<<" ";
	print_preorder(root->left);
	print_preorder(root->right);
}

void print_inorder(TreeNode *root){
	/*TODO*/
	if(root==NULL)
		return;
	
	print_inorder(root->left);
	cout<<root->data<<" ";
	print_inorder(root->right);
}

int main(){
	int preorder[] = {7,4,2, 3, 6, 5, 12, 9, 8, 11, 19,15, 20};
	int indexOfinorder[]={5,2,0,1,4,3,9,7,6,8,11,10,12};
	int size=sizeof(preorder)/sizeof(preorder[0]);
	TreeNode *root = buildTree(preorder,indexOfinorder,0,size-1);
	print_preorder(root);cout<<endl;
	print_inorder(root);cout<<endl;
}