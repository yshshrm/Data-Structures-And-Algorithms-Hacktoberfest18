#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *link;
};

struct node *START=NULL;

struct node* createNode() {
    struct node *n;
    n=(struct node *)malloc(sizeof(struct node));
    return(n);
}

void insertNode() {
    struct node *temp, *t;
    temp = createNode();
    printf("Enter a value: ");
    scanf("%d", &temp->data);
    temp->link = NULL;
    if(START == NULL) START = temp;
    else {
        t = START;
        while(t->link != NULL)
            t = t->link;
        t->link = temp;
    }
}

void deleteNode() {
    struct node *r;
    if(START == NULL) printf("List is empty\n");
    else {
        r = START;
        START = START->link;
        printf("First Node Deleted\n");
        free(r);
    }
}

void viewList() {
    struct node *t;
    if(START == NULL) printf("List is empty\n");
    else {
        t = START;
        printf("List looks like\n");
        while(t != NULL) {
            printf("%d ", t->data);
            t = t->link;
        }
        printf("\n");
    }
}

int menu() {
    int ch;
    printf("Enter your choice\t");
    scanf("%d", &ch);
    char ch;
    while( ( ch = getchar() ) != '\n' && ch != EOF );
    return(ch);
}

int main() {
    printf("1. Add value\n2. Delete first node\n3. View list\n4. Exit\n");
    while(1) {
        switch(menu()) {
            case 1: insertNode();
                    break;
            case 2: deleteNode();
                    break;
            case 3: viewList();
                    break;
            case 4: exit(0);
            default: printf("Invalid Choice\n");
        }
    }
    return 0;
}

