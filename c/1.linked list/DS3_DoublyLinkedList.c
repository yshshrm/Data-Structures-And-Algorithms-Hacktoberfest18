#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *prev, *next;
};

typedef struct node C;

C *start = NULL;

void node_at_start() {
    C *newnode;
    newnode = (C*)malloc(sizeof(C));
    printf("Enter a value: ");
    scanf("%d", &newnode->data);
    newnode->prev = NULL;
    newnode->next = NULL;
    if(start == NULL) start = newnode; //point to the new node
    else {
        start->prev = newnode;
        newnode->next = start;
        start = newnode;
    }
}

void node_at_end() {
    C *p, *t;  //t to traverse the list
    p=(C*)malloc(sizeof(C));
    printf("Enter a value: ");
    scanf("%d", &p->data);
    p->next = NULL; //last node now
    if(start == NULL) {
        p->prev = NULL; //becomes the first node in am empty list
        start = p;
    }
    else {
        //Traverse the list now
        t = start;
        while(t->next != NULL) {
            t = t->next; //Points to the last node
        }
        p->prev = t; //Becomes the last node now
        t->next = p;
    }
}

void node_in_between() {
    int i = 1, pos, val;
    C *new, *temp;

    printf("Enter a position: ");
    scanf("%d", &pos);
    printf("Enter a value: ");
    scanf("%d", &val);

    if(start == NULL) printf("Empty list\n");
    else {
        temp = start;
        while(i<pos-1 && temp != NULL) {
            temp = temp->next;
            i++;
        }
        if(temp != NULL) {
            new = (C*)malloc(sizeof(C));
            new->data = val;
            new->next = temp->next;
            new->prev = temp;
            if(temp->next != NULL) temp->next->prev = new;
            temp->next = new;
        }
        else printf("Invalid position\n");
    }
}

void traverse() {
    C *t;
    if(start == NULL) printf("List is empty\n");
    else {
        t = start;
        while(t != NULL) {
            printf("%d ", t->data);
            t = t->next;
        }
        printf("\n");
    }
}

void del_at_start() {
    C *d;
    if(start == NULL) {
        printf("Empty list, exiting now");
        exit(0);
    }
    else {
        d = start;
        start = start->next;
        free(d);
    }
}

void del_at_end() {
    C *e, *t;
    if(start == NULL) {
        printf("Empty list, exiting now");
        exit(0);
    }
    else {
        t = start;
        while(t->next != NULL) {
            t = t->next; //t points to the last node
        }
        e = t;
        t->prev->next = NULL;
        free(e);
    }
}

void del_in_between() {
    C *ptr;
    int i, pos;
    printf("Enter position: ");
    scanf("%d", &pos);
    ptr = start;
    for(i=1; i<pos && ptr != NULL; i++)
        ptr = ptr->next;
    if(ptr != NULL) {
        ptr->prev->next = ptr->next;
        ptr->next->prev = ptr->prev;
        free(ptr);
    }
    else
        printf("\nInvalid choice");
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
    printf("0. Node at position\n1. Insert node at the start\n2. Insert node at the end\n3. Traverse the list"
           "\n4. Delete at the start\n5. Delete at the end\n6. Delete at position\n7. Exit\n");
    while(1) {
        switch(menu()) {
            case 0: node_in_between();
            break;
            case 1: node_at_start();
            break;
            case 2: node_at_end();
            break;
            case 3: traverse();
            break;
            case 4: del_at_start();
            break;
            case 5: del_at_end();
            break;
            case 6: del_in_between();
            break;
            case 7: exit(0);
            default: printf("Invalid choice\n");
        }
    }
}
