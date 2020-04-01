//Double Linked List
//todo add delete and search functions
//Advantages wrt single linked
//traverse in forward and backward both direction
#include<iostream.h>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<alloc.h>

struct node{
int data;
struct node* left;
struct node* right;
};

struct node* root=NULL;

void append()
{
struct node* temp;
temp=(struct node*)malloc(sizeof(struct node));
printf("Enter data:");
scanf("%d",&temp->data);
temp->left=NULL;
temp->right=NULL;

if(root==NULL)
{
root=temp;
}
else
{
struct node* ptr;
ptr=root;
while(ptr->right!=NULL)
{
ptr=ptr->right;
}
ptr->right=temp;
temp->left=ptr;
}

}

void addBeg()
{
struct node* temp;
temp=(struct node*)malloc(sizeof(struct node));
printf("\nEnter data:");
scanf("%d",&temp->data);
temp->left=NULL;
temp->right=NULL;

if(root==NULL)
root=temp;
else
{
temp->right=root;
root->left=temp;
root=temp;
}

}

int totalNodes()
{
struct node* temp;
int count=0;
temp=root;
while(temp!=NULL)
{
temp=temp->right;
count++;
}
return count;
}

void display()
{
struct node* temp;
if(root==NULL)
printf("List is empty");
else
{
temp=root;
while(temp!=NULL)
{
printf("%d",temp->data);
if(temp->right!=NULL)
printf(" -> ");
temp=temp->right;
}
}

}
//adding after a specified node or at last
void addItAfter()
{
struct node* temp,*ptr;
int loc,i=1;
printf("\nEnter location:");
scanf("%d",&loc);
if(loc>totalNodes())
printf("\nInvalid Location[Exceeding]");
else
{
temp =(struct node*)malloc(sizeof(struct node));
printf("\nEnter data:");
scanf("%d",&temp->data);
temp->left=NULL;
temp->right=NULL;
ptr=root;
while(i<loc)
{
ptr=ptr->right;
i++;
}
temp->right=ptr->right;
ptr->right->left=temp;//pointer to pointer
temp->left=ptr;
ptr->right=temp;
}

}


void deleteItem()
{
if(root==NULL)
{
cout<<"\nUnderflow";
}
else
{
struct node *temp,*ptr;
int loc,i=1;
cout<<"\nEnter Location:";
cin>>loc;
if(loc==1)
{
cout<<"\nLocation to be deleted is:"<<root->data;
temp=root;
root=root->right;
cout<<"\nNow node 1 is:"<<root->data;
free(temp);
}
else if(loc>1&&loc<totalNodes())
{
temp=root;
while(temp!=NULL&&i<loc-1)
{
temp=temp->right;
i++;
}
ptr=temp->right;
cout<<"\nNode deleted is:"<<ptr->data;
temp->right=ptr->right;
temp->left->left=temp;
free(ptr);
free(temp);
}
else if(totalNodes()==loc)
{
ptr=root;
while(ptr->right->right!=NULL)
{
ptr=ptr->right;
}
temp=ptr->right;
ptr->right=NULL;
cout<<"\nDeleted data is:"<<temp->data;
free(temp);
}
else
{
cout<<"\nInvalid Location";
}
}
}

void main()
{
clrscr();
int ch;
while(1)
{
printf("\n1.Append \n2.No of Nodes \n3.Display\n4.Add After");
printf("\n5.Delete\n6.exit\n");
scanf("%d",&ch);
switch(ch)
{
case 1:append();
       printf("\n");
       break;
case 2:printf("\nTotal elements are:%d",totalNodes());
       printf("\n");
       break;
case 3:display();
       printf("\n");
       break;
case 4:addItAfter();
       printf("\n");
       break;
case 5:deleteItem();
       break;
case 6:exit(1);
       break;
default:printf("Wrong Choice");
}

}

}