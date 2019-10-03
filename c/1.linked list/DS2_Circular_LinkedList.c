#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *link;
};

typedef struct node C;
C *front=NULL, *rear = NULL, *temp;

void create() {
    C *newnode;
    newnode=(C*)malloc(sizeof(C));
    printf("Enter node value: ");
    scanf("%d", &newnode->data);
    newnode->link = NULL;
    if(rear==NULL) front = rear = newnode;
    else {
        rear->link = newnode;
        rear = newnode;
    }
    rear->link = front;
}

void del() {
    temp = front;
    if(front == NULL) printf("\nUnderflow: ");
    else {
        if(front == rear) {
            printf("\n%p", front->link);
            front = rear = NULL;
        }
        else {
            printf("\n%p", front->link);
            front = front->link;
            rear->link = front;
        }
        temp->link = NULL;
        free(temp);
    }
}

void display() {
    temp = front;
    if(front == NULL) printf("\nEmpty list");
    else {
        printf("\n");
        for(; temp != rear; temp=temp->link)
            printf("\n%d address=%p next=%p\t",temp->data,temp,temp->link);
        printf("\n%d address=%p next=%p\n",temp->data,temp,temp->link);
    }
}

int menu() {
    int ch;
    printf("Enter your choice: ");
    scanf("%d", &ch);
    char ch;
    while( ( ch = getchar() ) != '\n' && ch != EOF );
    return(ch);
}

int main() {
    printf("\n1. Insert node\n2. Delete node\n3. Display list\n4. Exit\n");
    while(1) {
        switch(menu()) {
            case 1: create();
            break;
            case 2: del();
            break;
            case 3: display();
            break;
            case 4: exit(0);
            default: printf("\nInvalid choice");
        }
    }
}
