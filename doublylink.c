#include<stdio.h>
#include<stdlib.h>

 struct node
 {

     int data;
     struct node *prev;
     struct node *next;
 }*top;
 typedef struct node node;

 node *create(int num)
 {
    node *temp= ( node*) malloc(sizeof(node));
    if(temp==NULL)
    return NULL;
    else
    {
      temp->data=num;
      temp->prev=NULL;
      temp->next=NULL;
      return temp;
    }
 }

void finsert(node *ptr)
{
    if(top==NULL)
        top=ptr;
    else
    {
        top->prev=ptr;
        ptr->next=top;
        top=ptr;
    }
}
void einsert(node *ptr)
{
    if(top==NULL)
        top=ptr;
    else
    {
        node* temp=top;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=ptr;
        ptr->prev=temp;

    }
}
void ainsert(node *ptr,int pos)
{
    int i;
    if(top==NULL)
        top=ptr;
    else
    {
      node *temp=top;
      for(i=0;i<pos-1;i++)
          temp=temp->next;
      ptr->prev=temp;
      ptr->next=temp->next;
      temp->next->prev=ptr;
      temp->next=ptr;
    }
}
void fdelete()
{
    if(top==NULL)
        printf("Underflow");
    else
    {
        top=top->next;
        top->prev=NULL;
    }
}
void edelete()
{
    if(top==NULL)
        printf("Underflow");
    else
    {
        node*temp=top;
        while(temp->next->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=NULL;
    }
}
void adelete(int pos)
{
    int i;
    if(top==NULL)
        printf("Underflow");
    else
    {
        node*temp=top;
        for(i=0;i<pos-1;i++)
            temp=temp->next;
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
    }
}



int main()
{
    int a=10;
    node *ptr=create(a);
    finsert(ptr);
    ptr=create(30);
    einsert(ptr);
    ptr=create(20);
    ainsert(ptr,1);
    //fdelete();
    //edelete();
    adelete(2);
    node*temp=top;
    while(temp!=NULL)
    {
        printf("%d -> ",temp->data);
        temp=temp->next;
    }

    return 0;


}
