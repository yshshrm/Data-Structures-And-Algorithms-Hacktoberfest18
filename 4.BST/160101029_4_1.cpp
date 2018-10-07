#include <iostream>
#include <cstdlib>


using namespace std;

struct node
{
	int data;
	struct node *left;
	struct node *right;
	node(int x){
		data=x;
		left=right=NULL;
	}
};
int pre_index=0;

struct node* buildTree(int pre[],int indexofinorder[],int start,int end)
{
	
	struct node *temp= new node(pre[pre_index]);

	if(start==end)
		return temp;

	else if(start<end)
	{
		int index=indexofinorder[pre_index];

    	temp->left=buildTree(pre,indexofinorder,0,index-1);
    	temp->right=buildTree(pre,indexofinorder,index+1,end);

    	return temp;
	}
    
    return NULL;


}
int findindex(int key,int pre[],int N)
{
	int count=0;
	int j;
	for(j=0;j<N;j++)
	{
		if(pre[j]<key)
			count++;
	}
	return count;

}


void printinorder(struct node *curr,int k1,int k2)
{
	if(curr==NULL)
		return;
	printinorder(curr->left,k1,k2);
	if(curr->data>=k1&&curr->data<=k2)
		cout<<curr->data<<" ";
	printinorder(curr->right,k1,k2);
}

	
int main()
{
	int N;
	cin>>N;
	int *pre=(int *)malloc(N*sizeof(int));
	int *indexofinorder=(int *)malloc(N*sizeof(int));
	int i;
	for(i=0;i<N;i++)
		cin>>pre[i];
	int k1,k2;
	cin>>k1;
	cin>>k2;
	
	for(i=0;i<N;i++)
	{
		indexofinorder[i]=findindex(pre[i],pre,N);
	}
	
	struct node *root=buildTree(pre,indexofinorder,0,N-1);
	
	printinorder(root,k1,k2);cout<<endl;

	return 0;
}