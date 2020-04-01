#include<stdio.h>
#include<conio.h>
struct queue
{
    int arr[50];
    int front;
    int rear;
    int cs;
    int maxs;

}q;
void create ()
{
    q.front=0;
    q.maxs=10;
    q.rear=q.maxs-1;
    q.cs=0;

}
void enqueue(int d)
{
    if(q.cs==q.maxs)
    {
        printf("\n Queue is full");
    }
    else
    {
        q.rear=(q.rear+1)%q.maxs;
        q.arr[q.rear]=d;
        q.cs++;

    }
}
void dequeue()
{
    if(q.cs==0)
    {
        printf("\n Queue is empty ");
    }
    else
    {
        q.front=(q.front+1)%q.maxs;
        q.cs--;
    }
}
int top()
{
    if(q.cs==0)
    {
        printf("\n No more elements in queue ");
        return -1;
    }
    else
    {
        return q.arr[q.front];
    }
}
void main()
{
    create();
    int t,y,n,i=0;
    printf("\n Enter the number of elements to be inserted in a queue ");
    scanf("%d",&t);
    while(i<t)
    {
        printf("\n Enter your element ");
        scanf("%d",&y);
        enqueue(y);
        i++;
    }
    printf("\n Enter the number of elements to be popped ");
    scanf("%d",&n);
    i=0;
    while(i<n)
    {
        int w=top();
        printf("\n The element popped is %d ",w);
        dequeue();
        i++;
    }
    enqueue(11);
    getch();
}
