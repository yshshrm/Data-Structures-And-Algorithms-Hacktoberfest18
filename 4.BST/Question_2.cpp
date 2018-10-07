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
TreeNode* buildTree(vector<int> &preorder,vector<int> &indexOfinorder,int start,int end){
	if(start<=end){
		TreeNode *node = new TreeNode(preorder[preorder_index]);
		int inorder_index = /*TODO*/ ;
		node->left = /*TODO*/;
		node->right = /*TODO*/;
		return /*TODO*/;
	}
	else
		return /*TODO*/;
}

void print_preorder(TreeNode *root){
	/*TODO*/
}

void print_inorder(TreeNode *root){
	/*TODO*/
}

int main(){
	vector<int> preorder = {7,4,2, 3, 6, 5, 12, 9, 8, 11, 19,15, 20},indexOfinorder={5,2,0,1,4,3,9,7,6,8,11,10,12};
	TreeNode *root = buildTree(preorder,indexOfinorder,0,indexOfinorder.size()-1);
	print_preorder(root);cout<<endl;
	print_inorder(root);cout<<endl;
}