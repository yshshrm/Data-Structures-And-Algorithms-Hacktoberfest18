#include<stdio.h> 
#include<stdlib.h> 
  
struct Node 
{ 
    int data; 
    struct Node* next; 
}; 
  
/* Function to get the middle of the linked list*/
void printMiddle(struct Node *head) 
{ 
    struct Node *slow_ptr = head; 
    struct Node *fast_ptr = head; 
  
    if (head!=NULL) 
    { 
        while (fast_ptr != NULL && fast_ptr->next != NULL) 
        { 
            fast_ptr = fast_ptr->next->next; 
            slow_ptr = slow_ptr->next; 
        } 
        printf("The middle element is [%d]\n\n", slow_ptr->data); 
    } 
} 
  
void push(struct Node** head_ref, int new_data) 
{ 
     struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
     new_node->data  = new_data; 
     new_node->next = (*head_ref); 
    (*head_ref) = new_node; 
} 
  
// function to print a given linked list 
void print(struct Node *ptr) 
{ 
    while (ptr != NULL) 
    { 
        printf("%d->", ptr->data); 
        ptr = ptr->next; 
    } 
    printf("NULL\n"); 
} 
  
int main() 
{ 
    /* Start with the empty list */
    struct Node* head = NULL; 
    int i; 
  
    for (i=5; i>0; i--) 
    { 
        push(&head, i); 
        print(head); 
        printMiddle(head); 
    } 
  
    return 0; 
} 
