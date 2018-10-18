#include<stdio.h>
#include<conio.h>
#include<malloc.h>
#include<algorithm>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct node
{
	struct node *lc;
	unsigned int data;
	struct node *rc;
};
typedef struct node N;
int A[1000];
N *new_node()
{
	N* temp;
	int x;
	string n,nx("n");
    printf("\nEnter n for no data or y For Yes:");
    cin>>n;
    cout<<endl;
    if(n==nx)
    {
		return NULL;	
	}
    else
	{  
		temp = (struct node*)malloc(sizeof(struct node));   
		cout<<endl<<"Enter data:";
		cin>>x;
		temp->data=x;
    	cout<<"\nEnter left child of "<<x;
    	temp->lc=new_node();
    	cout<<"\nEnter right child of "<<x;
    	temp->rc=new_node();
	}
    
	return temp;
}
void printInorder(N *root)
{
	if(root==NULL)//base case
		return;
		
	printInorder(root->lc);
	cout<<root->data;
	printInorder(root->rc);
}

void printPostorder(N *root)
{
	if(root==NULL)//base case
		return;
	
	printPostorder(root->lc);
	printPostorder(root->rc);
	cout<<root->data;
}

void printPreorder(N *root)
{
	if(root==NULL)//base case
		return;
	cout<<root->data;
	printPreorder(root->lc);
	printPreorder(root->rc);
}
int total_node(N *root) //Total No of Nodes
{
	if(root==NULL)//base case
		return 0;
	else
		return 1+total_node(root->lc)+total_node(root->rc);
}
int height(N *root) //Max Depth or Height
{
	if(root==NULL)//base case
		return 0;
	else
	{
		int lh=height(root->lc);
		int rh=height(root->rc);
		
		if(lh>rh)
			return (lh+1);
		else
			return (rh+1);	
	}
}
bool id(N *root,N *root1)//Identical tree
{
	if(root==NULL && root1==NULL)//base case
		return 1;
	if((root!=NULL && root1!=NULL) && (root->data == root1->data) && id(root->lc,root1->lc) && id(root->rc,root1->rc))
	{
		return 1;
  	}
	else
		return 0;
}
bool h_b(N *root)//Height Balance
{
	if(root==NULL)//base case
		return 1;
	else 
	{
		int lh=height(root->lc);
		int rh=height(root->rc);
		
		if((abs(lh-rh)<=2)&&(h_b(root->lc))&&(h_b(root->rc)))
			return 1;
		else
			return 0;
    }
}
bool ChildSum(N *root)//Children Sum i.e., sum chlid value equals to parent value
{
	int lx=0,rx=0;
	if(root==NULL || (root->rc==NULL && root->lc==NULL))//base case
		return 1;
	if(root->lc)
		lx=root->lc->data;
	if(root->rc)
		rx=root->rc->data;
		
	if(((lx+rx)==root->data)&&ChildSum(root->lc)&&ChildSum(root->rc))
		return 1;
	else
		return 0;
}

int dia(N *root)//width or diameter
{
	if(root==NULL)
		return 0;
	else
	{
		int lh=height(root->lc);
		int rh=height(root->rc);
		int total_d=lh+rh+1;
		int dia_left=dia(root->lc);
		int dia_right=dia(root->rc);
		
		return std::max(total_d, max(dia_left, dia_right));
	}
}

int rtls(N *root, int val=0)// Root To Leaf Sum
{
	if(root==NULL)
	{
		if(val==0)
			return 1;
		else
			return 0;	
	}
	
	int total=val-root->data;
	if(root->lc==NULL && root->rc==NULL && total==0)
		return 1;
	else
		return 0;
	
	bool X,Y;	
	if(root->lc)
		X = rtls(root->lc, total);
	if(root->rc)
		Y = rtls(root->rc, total);
	
	if(X||Y)
		return 1;
	else
		return 0;
}

int count_leaf(N *root)
{
	if(root==NULL)
		return 0;
	if(root->lc==NULL && root->rc==NULL)
		return 1;
	else
		return count_leaf(root->lc)+count_leaf(root->rc);	
}
int print_leaf(N *root)
{
	if(root!=NULL)
	{
		print_leaf(root->lc);
		if(root->lc==NULL && root->rc==NULL)
			return root->data;
		print_leaf(root->rc);	
	}	
}
void print_path(N* root, int top)
{
	if(root==NULL)
		return;
	A[top]=root->data;
	if(root->lc==NULL && root->rc==NULL)
	{
		for(int i=0;i<=top;i++)
			cout<<A[i];
		cout<<endl;
		return;
	}
	print_path(root->lc,top+1);
	print_path(root->rc,top+1);
}

N* LCA(N* root, int a, int b)
{
	if(root==NULL)
		return NULL;
	if(root->data==a || root->data==b)
		return root;
	N* x=LCA(root->lc, a, b);
	N* y=LCA(root->rc, a, b);
	
	if(x==NULL && y==NULL)
		return NULL;
	
	if(x!=NULL && y!=NULL)
		return root;
	if(x!=NULL)
		return x;
	else
		return y;
}

void LevelOrder(N* root)
{
	int h1=height(root);
	queue<N*>s1;
	queue<N*>s2;
	s1.push(root);
	vector<int>v[h1];
	int i=0; 
	while(i<=h1)
	{
		while(!s1.empty())
		{
			N* temp = s1.front();
			v[i].push_back(temp->data);
			if(temp->lc!=NULL)
				s2.push(temp->lc);
			if(temp->rc!=NULL)
				s2.push(temp->rc);
			s1.pop();	
		}
		i++;
		while(!s2.empty())
		{
			N* temp = s2.front();
			v[i].push_back(temp->data);
			if(temp->lc!=NULL)
				s1.push(temp->lc);
			if(temp->rc!=NULL)
				s1.push(temp->rc);
			s2.pop();	
		}
		i++;
	}
	for(int j=0;j<h1;j++)
	{
		if(j%2==1)
		for(int k=0;k<v[j].size();k++)
			cout<<v[j][k];
		else
		for(int k=v[j].size()-1;k>=0;k--)
			cout<<v[j][k];
	}
	
}

void print_boundary_left(N *root)
{
	if(root)
	{
		if(root->lc)
		{
			cout<<root->data;
			print_boundary_left(root->lc);
		}
		else if(root->rc)
		{
			cout<<root->data;
			print_boundary_left(root->rc);
		}
	}
}

void print_boundary_right(N *root)
{
	if(root)
	{
		if(root->rc)
		{
			print_boundary_right(root->rc);
			cout<<root->data;
		}
		else if(root->lc)
		{
			print_boundary_right(root->lc);
			cout<<root->data;
		}
	}
}


void print_boundary(N *root)
{
	if(root!=NULL)
	{
		cout<<root->data;
		print_boundary_left(root->lc);
		print_leaf(root->lc);
		print_leaf(root->rc);
		print_boundary_right(root->rc);
	}	
}

int main()
{
	N* root = new_node();
	
	
/*	N* root1 = new_node();
	
	
	cout<<"\nPreorder traversal of binary tree is \n";
    printPreorder(root);
	
	cout<<"\nInorder traversal of binary tree is \n";
    printInorder(root);
    
    cout<<"\nPostorder traversal of binary tree is \n";
    printPostorder(root);

    
    cout<<endl<<total_node(root);
    cout<<endl<<id(root,root1);
    
    cout<<endl<<height(root);
    
    cout<<endl<<h_b(root1)<<endl;
    
    cout<<ChildSum(root)<<endl;
    
    cout<<dia(root)<<endl;
    
    cout<<rtls(root,10)<<endl;
    
    cout<<count_leaf(root)<<endl;
    
    print_path(root,0);*/
    
    N* r=LCA(root,7,8);
    cout<<r->data<<endl;
    
    LevelOrder(root);
    cout<<endl;
    print_boundary(root);
    
	getch();
	return 0;
}
