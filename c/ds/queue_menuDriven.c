#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *head=NULL,*tail=NULL;

void enqueue()
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    struct node *temp1=tail;
    int n;
    printf("Enter the value to be inserted : ");
    scanf("%d",&n);
    temp->data=n;
    temp->next=NULL;
    if(head==NULL && tail==NULL)
    {
        head=temp;
        tail=temp;
    }
    else
    {
        temp1->next=temp;
        tail=temp;
    }
}
void dequeue()
{
    struct node *temp=head;
    if(head==NULL && tail==NULL)
        printf("Queue empty !!! \n");
    else if(temp->next==NULL)
    {
        printf("%d is dequeued.\n",temp->data);
        head=NULL;
        tail=NULL;
    }
    else
    {
        printf("%d is dequeued.\n",temp->data);
        head=temp->next;
        temp->next=NULL;
    }
}
void top_ele()
{
    struct node*temp=head;
    if(head==NULL && tail==NULL)
        printf("Queue empty !!!\n");
    else
        printf("Top element is %d .\n",temp->data);
}
void print()
{
    struct node *temp=head;
    if(head==NULL && tail==NULL)
        printf("Queue empty !!!\n");
    else
    {
        printf("Queue is : ");
        while(temp->next!=NULL)
        {
            printf("%d  ",temp->data);
            temp=temp->next;
        }
        printf("%d\n",temp->data);
    }
}
void main()
{
    int k;
    do
    {
        printf("1.Enqueue\n2.Dequeue\n3.Top\n4.Display\n5.Exit\n");
        scanf("%d",&k);
        switch(k)
        {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                top_ele();
                break;
            case 4:
                print();
                break;
            case 5:
                exit(0);
        }
    }while(1);
}
