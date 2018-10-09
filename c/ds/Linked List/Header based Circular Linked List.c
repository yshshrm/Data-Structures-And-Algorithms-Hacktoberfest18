#include<stdio.h>
#include<stdlib.h>

struct DNode {
    int info;
    struct DNode *next;
    struct DNode *prev;
};
typedef struct DNode DNODE;

DNODE *insertEnd(DNODE *head, int val) {
    DNODE *p = (DNODE *)malloc(sizeof(DNODE));
    p->info = val;
    p->next = NULL;
    p->prev = NULL;
    if(head == NULL) {
        head = p;
        return head;
    }
    DNODE *q = head;
    while(q->next != NULL) {
        q = q->next;
    }
    q->next = p;
    p->prev = q;
    return head;
}

DNODE *insertStart(DNODE *head, int val) {
    DNODE *p = (DNODE *)malloc(sizeof(DNODE));
    p->info = val;
    p->next = head;
    p->prev = NULL;
    head = p;
    return head;
}

DNODE *insertAfter(DNODE *head, int val, int key) {
    if(head == NULL) {
        printf("List is empty");
        return head;
    }
    DNODE *q=head;
    while(q->info!=key) {
        q = q->next;
        if(q == NULL) {
            printf("List is empty");
            return head;
        }
    }
    DNODE *p = (DNODE *)malloc(sizeof(DNODE));
    p->info = val;
    p->next = q->next;
    if(q->next != NULL)
        q->next->prev = p;
    q->next = p;
    p->prev = q;
    return head;
}

DNODE *insertBefore(DNODE *head, int val, int key) {
    if(head == NULL) {
        printf("List is empty");
        return head;
    }
    DNODE *q=head;
    while(q->info!=key) {
        q = q->next;
        if(q == NULL) {
            printf("X not found");
            return head;
        }
    }
    DNODE *p = (DNODE *)malloc(sizeof(DNODE));
    p->info = val;
    p->next = q;
    p->prev = q->prev;
    q->prev = p;
    if(p->prev != NULL)
        p->prev->next = p;
    else
        head = p;
    return head;
}
DNODE *deletionS(DNODE *head){
  if(head == NULL) {
      printf("List is already empty.");
      return head;
  }
  DNODE *q=head;
    head= head->next;
    if(head!=NULL){
      head->prev=NULL;
    }
    free(q);
    return head;
}

DNODE *deletionE(DNODE *head){
  if (head==NULL){
    printf("List is empty");
  }
  DNODE *q = head;
  while(q->next != NULL) {
      q = q->next;
  }
  if(q->prev != NULL)
      q->prev->next = q->next;
  free(q);
  return head;
}

DNODE *deletion(DNODE *head, int key) {
    if(head == NULL) {
        printf("List is already empty.");
        return head;
    }
    DNODE *q=head;
    while(q->info!=key) {
        q = q->next;
        if(q == NULL) {
            printf("Element not found");
            return head;
        }
    }
    if(q->next != NULL)
        q->next->prev = q->prev;
    if(q->prev != NULL)
        q->prev->next = q->next;
    else
        head = q->next;
    q->next = q->prev = NULL;
    free(q);
    return head;
}

void display(DNODE *head) {
    if(head == NULL) {
        printf("List is empty");
        return ;
    }
    DNODE *q = head;
    while(q!=NULL) {
        printf("%d \t", q->info);
        q = q->next;
    }
}

void main() {
    DNODE *head = NULL;
    int input,val,key;
    while(1) {
        printf("\n1. Create a doubly linked list.\n");
        printf("2. Insert an element at the start of the doubly linked list.\n");
        printf("3. Insert an element at the end of the doubly linked list.\n");
        printf("4. Insert an element before an existing element whose information is x in a doubly linked list.\n");
        printf("5. Insert an element after an existing element whose information is x in a doubly linked list.\n");
        printf("6. Delete the first element of the doubly linked list.\n");
        printf("7. Delete the last element of the doubly linked list.\n");
        printf("8. Delete the element whose information is x from a doubly linked list.\n");
        printf("9. Display list.\n");
        printf("10. quit.\n");
        printf("Enter your choice: ");
        scanf("%d",&input);
        switch(input) {
            case 1:
                head = NULL;
                printf("New list is created.\n");
                break;
            case 2:
                printf("Enter element to insert: ");
                scanf("%d", &val);
                head = insertStart(head,val);
                break;
            case 3:
                printf("Enter element to insert: ");
                scanf("%d", &val);
                head = insertEnd(head,val);
                break;
            case 4:
                printf("Enter element to insert: ");
                scanf("%d", &val);
                printf("Enter key before you want to insert: ");
                scanf("%d", &key);
                head = insertBefore(head,val,key);
                break;
            case 5:
                printf("Enter element to insert: ");
                scanf("%d", &val);
                printf("Enter key after you want to insert: ");
                scanf("%d", &key);
                head = insertAfter(head,val,key);
                break;
            case 6:
                printf("Action performed");
                head = deletionS(head);
                break;
            case 7:
                printf("Action performed");
                head = deletionE(head);
                break;
            case 8:
                printf("Enter key which you want to delete: ");
                scanf("%d", &key);
                head = deletion(head,key);
                break;
            case 9:
                display(head);
                break;
            case 10:
                exit(1);
            default:
                printf("Enter number in between 1 to 10.\n");
        }
    }
}
