##include <stdio.h>
#include<stdlib.h>

typedef struct sel
{
    int data;
    struct sel* left;
    struct sel* right;
}node;

node* createNode(int key)
{
    node* temp=(node*)malloc(sizeof(node));
    temp->data=key;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
node* insertNode(node* root, int key)
{
    if(root==NULL)
    {
        return createNode(key);
    }
    else
    {
        if(root->data<key)
        {
            root->right=insertNode(root->right,key);   
        }
        else
        {
            root->left=insertNode(root->left,key);   
        }
        return root;
    }
}

int getMax(node* root, int mn, int mx)
{
    if(root!=NULL)
    {
        if(root->data>mx)
        {
            return getMax(root->left,mn,mx);
        }
        else if(root->data<mn)
        {
            return getMax(root->right,mn,mx);
        }
        else
        {
            int mxm=0;
            node* temp=root;
            mxm=root->data;
            while(temp!=NULL && temp->data!=mx)
            {
                if(temp->data>mx)
                {
                    if(mxm<temp->data)
                    {
                        mxm=temp->data; 
                    }
                    temp=temp->left;
                }
                else
                {
                    temp=temp->right;
                }
            }
            if(mxm<mx)
            {
                mxm=mx;
            }
            return mxm;
        }
    }
   
}
int main()
{
    //printf("Hello World!\n");
    int n;
    scanf("%d",&n);
    int* arr=(int*)malloc(n*sizeof(int));
    int i;
    node* root=NULL;
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
        root=insertNode(root,arr[i]);
    }
    int a,b;
    scanf("%d %d",&a,&b);
    int mn=(a<b?a:b);
    //printf("%d ",mn);
    int mx=a+b-mn;
    //printf("%d\n ",mx);
    int ans=getMax(root,mn,mx);
    printf("%d ",ans);
    return 0;
}
