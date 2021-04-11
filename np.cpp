#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<iostream>
using namespace std;
struct node
{
  int data;
  struct node* left;
  struct node* right;
};
typedef struct node N;
int search(int arr[], int strt, int end, int value);
struct node* newNode(int data);
 

struct node* buildTree(int in[], int pre[], int inStrt, int inEnd)
{
  static int preIndex = 0;
 
  if(inStrt > inEnd)
     return NULL;
 

  struct node *tNode = newNode(pre[preIndex++]);
 
  if(inStrt == inEnd)
    return tNode;
 
  int inIndex = search(in, inStrt, inEnd, tNode->data);
 
 
  tNode->left = buildTree(in, pre, inStrt, inIndex-1);
  tNode->right = buildTree(in, pre, inIndex+1, inEnd);
 
  return tNode;
}
 
int search(int arr[], int strt, int end, int value)
{
  int i;
  for(i = strt; i <= end; i++)
  {
    if(arr[i] == value)
      return i;
  }
}
 
struct node* newNode(int data)
{
  struct node* node = (struct node*)malloc(sizeof(struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
 
  return(node);
}
 
void printPostorder(struct node* node)
{
  if (node == NULL)
     return;
    
  printPostorder(node->left);
 
  printPostorder(node->right);
  
  cout<<node->data;
}
int rtls(N *root, int val)// Root To Leaf Sum
{
	if(root==NULL)
	{
		if(val==0)
			return root->data;
		else
			return 0;	
	}
	
	int total=val-root->data;
	if(root->left==NULL && root->right==NULL && total==0)
		return root->data;
	else
		return 0;
	
	bool X,Y;	
	if(root->left)
		X = rtls(root->left, total);
	if(root->right)
		Y = rtls(root->right, total);
	
	if(X||Y)
		return root->data;
	

}
int main()
{
  int n,i,val;
  cin>>n;
  int in[n+1],pre[n+1];
  for(i=0;i<n;i++)
  {
      cin>>in[i];
  }
  for(i=0;i<n;i++)
  {
      cin>>pre[i];
  }
  cin>>val;
  struct node *root = buildTree(in, pre, 0, n - 1);
  cout<<rtls(root,val);
  getch();
  return 0;
}
