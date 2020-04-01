/*

	Given a binary tree, print the preorder traversal of given tree.
	Pre-order traversal is: Root LeftChild RightChild.
	(If any node does not have left or right child, take -1 in its place)

	Sample Input :
	8 3 10 1 6 -1 14 -1 -1 4 7 13 -1 -1 -1 -1 -1 -1 -1
	Sample Output :
	8 3 1 6 4 7 10 14 13

*/


#include<iostream>
#include<queue>
using namespace std;

template <typename T>
class BinaryTreeNode
{
    public : 
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data)
    {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
};

BinaryTreeNode<int>* takeInput() {

    int rootData;
    cout << "Enter root data : ";
    cin >> rootData;
    if(rootData == -1)
        return NULL;

    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while(!q.empty()) 
    {

        BinaryTreeNode<int> *currentNode = q.front();
	q.pop();
        int leftChild, rightChild;
        cout << "Enter left child of " << currentNode -> data << " : ";
        cin >> leftChild;
        if(leftChild != -1)
	{
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode -> left =leftNode;
            q.push(leftNode);
        }
        
	cout << "Enter right child of " << currentNode -> data << " : ";
        cin >> rightChild;
        if(rightChild != -1) 
	{
            BinaryTreeNode<int>* rightNode = new BinaryTreeNode<int>(rightChild);
            currentNode -> right =rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

void preOrder(BinaryTreeNode<int> *root)
{
    
  if(root == NULL)
    	return;
  
  cout << root->data << " ";
  
  preOrder(root->left);
  preOrder(root->right);
  
}

int main()
{

    BinaryTreeNode<int>* root = takeInput();
    preOrder(root);

}

