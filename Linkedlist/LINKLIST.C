#include<stdio.h>
#include<conio.h>
void append();
void display();
void length();
void insertatbegin();
void insertatmiddle();
struct node
{int data;
struct node *link;
}*root=NULL;
void main()
{
int a;
char che;
clrscr();
do{
printf("CHOOSE OPTION \n 1.APPEND\n 2.DISPLAY\n 3.LENGTH OF LINK LIST\n 4.INSERT AT BEGIN\n 5.INSERT AT MIDDLE ");
scanf("%d",&a);
switch(a)
{
case 1:{append();
break;}
case 2:{display();
break;}
case 3:{length();
break;}
case 4:{
insertatbegin();
break;
}
case 5:{
insertatmiddle();
break;
}
default:printf("ENTER WRONG CHOICE\n");
}
printf("Want to choose option again(Y) ");
scanf(" %c",&che);
}while(che=='y'||che=='Y');
getch();
}
void append()
{char ch;
do
{
struct node *temp;
temp=(struct node*)malloc(sizeof(struct node));
printf("ENTER THE DATA \n");
scanf("%d",&temp->data);
temp->link=NULL;
if(root==NULL)
{root=temp;}
else
{struct node *temp1;
temp1=root;
while(temp1->link!=NULL)
{
temp1=temp1->link;
}
temp1->link=temp;
}
printf("DO YOU WANT TO ENTER MORE (Y) ");
scanf(" %c",&ch);}
while(ch=='Y'||ch=='y');
}
void display()
{
struct node *temp;
temp=root;
if(temp==NULL)
{printf("NO NODE IN THE LINK LIST \n");
}
else
{while(temp!=NULL)
{printf("%d\n",temp->data);
temp=temp->link;
}
}
}
void length()
{int count=0;
struct node *temp;
temp=root;
while(temp!=NULL)
{count++;
temp=temp->link;
}
printf("LENGTH OF LINK LIST %d",count);
}
void insertatbegin()
{
struct node *temp;
temp=(struct node*)malloc(sizeof(struct node));
printf("ENTER THE DATA \n");
scanf("%d",&temp->data);
temp->link=NULL;
if(root==NULL)
{root=temp;
}
else
{
temp->link=root;
root=temp;
}
}
void insertatmiddle()
{
int len,i,count=0;
struct node *temp,*temp1;
temp=(struct node*)malloc(sizeof(struct node));
printf("ENTER THE DATA \n");
scanf("%d",&temp->data);
temp->link=NULL;
printf("Enter The Location You Want To Enter The Data");
scanf("%d",&len);
temp1=root;
while(temp1!=NULL)
{
temp1=temp1->link;
count++;
}
if(len>count)
printf("Insertion Not Valid");
else
{
while(i<len)
{
temp1=temp1->link;
}
if(root==NULL)
{
root=temp;
}
else
{
temp->link=temp1->link;
temp1->link=temp;
}
}
}