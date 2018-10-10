//
//  CDLL.c


#include "CDLL.h"

struct node {
    int key, count;
    nodeptr_t next, prev;
};


//------------------------Function Definitions-------------------------//
// A function to check if the head is empty or not
bool isEmpty(nodeptr_t head){
    return head == NULL;
}

//--------------------------------------------------------------------------------------------------------------------------------------------------------
// A function to Create the node and initializes information in it: key and count
nodeptr_t CreateNodeCDLL(int key_value){

    nodeptr_t nn = (nodeptr_t) malloc(sizeof(struct node));
    nn->key = key_value;
    nn->next = NULL;
    nn->prev = NULL;

    return nn;
}

//--------------------------------------------------------------------------------------------------------------------------------------------------------
// A function to Insert a node, keeping the list in sorted order. It assumes the node has been created and is passed as an argument.
void InsertListCDLL(nodeptr_t *nn, nodeptr_t *head){

    nodeptr_t current = *head;
    nodeptr_t temp = *head, temp2;


    // if list is empty
    if (*head == NULL){

        // set the new node as the head of the list
        (*nn)->prev = (*nn)->next = NULL;
        *head = *nn;}

    //list not empty
    else{
        if((*nn)->key < current->key){

            while(current->next != temp){
                current=current->next;}

            current->next=*nn;

            (*nn)->next=*head;

            *head=*nn;
        }

        else{
             while(((*nn)->key > current->key) && (current->next->key < (*nn)->key) && current->next!=temp)
             {current=current->next;}

            temp2=current->next;
            current->next = *nn;
            (*nn)->next = temp2;
        }
    }
}

//--------------------------------------------------------------------------------------------------------------------------------------------------------
// A function to Delete a node from the list and free it.
void DeleteNodeCDLL(int value,nodeptr_t *head)
{
    nodeptr_t del, temp;

    //initiliaze del and temp
    del = *head;

    // base case
    if(*head == NULL){
        printf("Can't delete from empty list!\n");
        return;}

    else{

        while(del!=NULL && del->key!=value)
            del=del->next;

        temp = del->prev;
        temp->next = del->next;

        if(del->next!=NULL)
            (del->next)->prev = temp;}


    return;}

//--------------------------------------------------------------------------------------------------------------------------------------------------------
// A function to Print the list in forward traversal order.
void PrintListCDLL(nodeptr_t *head){

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
int LengthCDLL(nodeptr_t *head) {

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
