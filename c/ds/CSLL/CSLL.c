//
//  CSLL.c

#include "CSLL.h"

struct node {
    int count;
    int key;
    nodeptr_t next;
};


/*------------------------Function Definitions-------------------------*/

// A function to check if the head is empty or not
bool isEmpty(nodeptr_t head){
    return head == NULL;
}

//--------------------------------------------------------------------------------------------------------------------------------------------------------
// A function to Create the node and initializes information in it: key and count
nodeptr_t CreateNodeCSLL(int key_value, nodeptr_t *head){

    nodeptr_t nn = (nodeptr_t) malloc(sizeof(struct node));

    // Assign information to the new node
    nn->key = key_value;
    nn->next = NULL;
    nn->count = 0;
    return nn;
}

//--------------------------------------------------------------------------------------------------------------------------------------------------------
// A function to Insert a node, keeping the list in sorted order. It assumes the node has been created and is passed as an argument.
void InsertListCSLL(nodeptr_t *nn, nodeptr_t *head){

    nodeptr_t temp = *head;
    nodeptr_t temp2, current = *head;

    //when list empty
    if(*head==NULL){

        (*nn)->next=*nn;
        *head=*nn;}

    //when list not empty
    else{

        if((*nn)->key < current->key){

            while(current->next!=temp)
                current=current->next;

            current->next=(*nn);

            (*nn)->next=*head;

            *head=(*nn);}

        else{

            while(((*nn)->key > current->key) && (current->next->key < (*nn)->key) && current->next!=temp){

                current=current->next;}

            temp2=current->next;

            current->next=(*nn);

            (*nn)->next=temp2;}
    }
}

//--------------------------------------------------------------------------------------------------------------------------------------------------------
// A function to Delete a node from the list and free it.
void DeleteNodeCSLL(int key_value, nodeptr_t *head){

    nodeptr_t current = *head;
    nodeptr_t temp;

   while(current->next != *head && current->next->key != key_value)
       current=current->next;

    if(current->next != NULL){
        temp = current->next;
        current->next = temp->next;
        free(temp);
    }
}

//--------------------------------------------------------------------------------------------------------------------------------------------------------
// A function to Print the list.
void PrintListCSLL(nodeptr_t *head) {

    nodeptr_t w = *head;  // walker to traverse the list

    if(isEmpty(*head)){
        printf("List is empty.\n");}
    else{

        while (w != NULL) {
            printf(" %d " ,w->key);
            w = w->next;}
    }
    printf("\n\n");
    return;
}

//--------------------------------------------------------------------------------------------------------------------------------------------------------
// A function to compute the Length of the list.
int LengthCSLL(nodeptr_t *head) {

    // assign head to local variable
    nodeptr_t current = *head;
    int count_list = 0;

    // use var 'current' to traverse list + count nodes
    while (current != NULL) {
        count_list++;
        current = current->next;
    }
    return count_list;
}
