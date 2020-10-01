#include <stdio.h>
#define MAXSIZE 4
int queue[MAXSIZE],front=0,rear=0,item;
int Qinsert(item);
int Qdelete();
int Qdisplay();
int main(){
    int ch,item;
    while(1){
        printf("\n\nOptions to choose:-\n");
        printf("1.Insert element in a queue\n2.Delete element of a queue\n3.Display element of the queue\n4.Exit\n");
        printf("Enter your choice : ");
        scanf("%d",&ch);
        switch(ch){
        case 1:
            printf("Enter the item to be inserted:");
            scanf("%d",&item);
            Qinsert(item);
            break;
        case 2:
            Qdelete();
            break;
        case 3:
           Qdisplay();
           break;
        case 4:
            exit(1);
        }
    }
    return 0;
}
int Qinsert(int item){
    if(rear==MAXSIZE){
        printf("Queue Overflow");
        return;
    }
    else
        rear=rear+1;
    queue[rear]=item;
    if(front==0)
        front=1;
    return;
}
int Qdelete(){
    if(front==0 || front>rear){
        printf("Queue Underflow");
        return;
    }
    else{
        printf("Element deleted is %d\n",queue[front]);
        front=front+1;
    }
    return ;
}
int Qdisplay(){
    int i;
    if(front==0){
        printf("Queue Empty");
        return;
    }
     for(i=1;i<=front-1;i++){
      printf("-- ");
    }
    for(i=front;i<=rear;i++){
      printf("%d ",queue[i]);
    }
     for(i=rear+1;i<=MAXSIZE;i++){
      printf("-- ");
    }
    return;
}
