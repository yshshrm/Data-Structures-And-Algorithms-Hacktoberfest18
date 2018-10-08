//
//  SLL.c

#include "SLL.h"

/* Definition of struct node */
struct node {
    int key, count;
    nodeptr_t next;
};


/*------------------------Function Definitions-------------------------*/

// A function to check if the head is empty or not
bool isEmpty(nodeptr_t head) {
    return head == NULL;
}

//--------------------------------------------------------------------------------------------------------------------------------------------------------
// A function to Create the node and initializes information in it: key and count
nodeptr_t CreateNodeSLL(int key_value, nodeptr_t *head){

    nodeptr_t nn = (nodeptr_t) malloc(sizeof(struct node));
    nn->key = key_value;
    nn->count = 1;
    nn->next = NULL;

    return nn;
}

//--------------------------------------------------------------------------------------------------------------------------------------------------------
// A function to Insert a node, keeping the list in sorted order. It assumes the node has been created and is passed as an argument.
void InsertListSLL(nodeptr_t nn, nodeptr_t *head) {

    nodeptr_t w;

    // when list is empty
    if (!(*head)) {
        *head = nn;
        (*head)->next = NULL;}

    // when list not empty
    else{

        if((*head)->key == nn->key){
            (*head)->count++;}

        else if((*head)->key > nn->key){
            nn->next = *head;
            *head = nn;
        }

        else {
            int flag = 0;
            w = *head;
            while(w->next != NULL){

                if(w->next->key == nn->key){
                    w = w->next;
                    w->count++;
                    flag = 1;
                    break;}

                else if(w->next->key > nn->key){
                    nn->next = w->next;
                    w->next = nn;
                    flag = 1;
                    break;
                }
                w=w->next;
            }
            if(!flag)
                w->next = nn;
        }


    }

}



//--------------------------------------------------------------------------------------------------------------------------------------------------------
// A function to Delete a node from the list and free it.
void DeleteNodeSLL(int key_value,nodeptr_t *head){

    nodeptr_t walker, previous;

    // if node to be deleted is head node
    if((*head)==NULL){
        printf("Can't delete from empty list!\n");
        return;}

    else {
        walker = (*head)->next;
        previous = *head;

        while(walker!= NULL){
            if(walker->key == key_value && walker->count == 1){
                previous->next = walker->next;
                free(walker);
                return;
            }
            previous = previous->next;
            walker = walker->next;
        }
    }
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------
// A function to Print the list.
void PrintListSLL(nodeptr_t *head) {

    nodeptr_t w = *head;  // walker to traverse the list

    if(isEmpty(*head)){
        printf("List is empty.\n");}
    else{

        while (w != NULL) {
            printf("key :  %d count : %d \n" ,w->key, w->count);
            w = w->next;}
    }
    printf("\n\n");
    return;
}

//--------------------------------------------------------------------------------------------------------------------------------------------------------
// A function to compute the Length of the list.
int LengthSLL(nodeptr_t *head) {

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
