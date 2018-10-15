
#include<stdio.h> 
#include<stdlib.h> 
struct Node 
{ 
    int data; 
    struct Node *next; 
}; 
  

void deleteAlt(struct Node *head) 
{ 
    if (head == NULL) 
        return;
    struct Node *prev = head; 
    struct Node *node = head->next; 
  
    while (prev != NULL && node != NULL) 
    { 
        prev->next = node->next;
        free(node); 
        prev = prev->next; 
        if (prev != NULL) 
            node = prev->next; 
    } 
} 
  

void push(struct Node** head_ref, int new_data) 
{ 
    struct Node* new_node =(struct Node*) malloc(sizeof(struct Node)); 
    new_node->data  = new_data; 
    new_node->next = (*head_ref); 
    (*head_ref)    = new_node; 
} 
  
void print(struct Node *node) 
{ 
    while (node != NULL) 
    { 
        printf("%d ", node->data); 
        node = node->next; 
    } 
} 

int main() 
{ 
  
    struct Node* head = NULL; 
    push(&head, 5); 
    push(&head, 4); 
    push(&head, 3); 
    push(&head, 2); 
    push(&head, 1); 
  
    printf("\nList before calling deleteAlt() \n"); 
    print(head);
    deleteAlt(head); 
    printf("\nList after calling deleteAlt() \n"); 
    print(head); 
  
    return 0; 
} 
