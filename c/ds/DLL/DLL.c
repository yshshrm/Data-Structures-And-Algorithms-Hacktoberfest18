//
//  DLL.c

 #include "DLL.h"

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
 nodeptr_t CreateNodeDLL(int key_value){

     nodeptr_t nn = (nodeptr_t) malloc(sizeof(struct node));
     nn->key = key_value;
     nn->next = NULL;
     nn->prev = NULL;
     nn->count = 1;

 return nn;
 }

//--------------------------------------------------------------------------------------------------------------------------------------------------------
// A function to Insert a node, keeping the list in sorted order. It assumes the node has been created and is passed as an argument.
 void InsertListDLL(nodeptr_t *nn, nodeptr_t *head){
     int found; // 1 means found a place to insert new node in, 0 means not

     // if list is empty
     if (*head == NULL){

         // set the new node as the head of the list
         (*nn)->prev = (*nn)->next = NULL;
         *head = *nn;
    }

     // List not empty
     else if((*nn)->key <= (*head)->key){

         if((*head)->key == (*nn)->key){
             (*head)->count++;}
         else{
            (*head)->prev = *nn;
             (*nn)->next = *head;
             *head = *nn;
         }
     }

     else{

         nodeptr_t current = NULL;

         current = *head;
         found = 0;

         while( (current->next != NULL))
         {
             //printf("in loop\n ");
             if ((*nn)->key < current->next->key){
                 //printf("found diff %d\n", current->key);
                 current->next->prev = *nn;
                 (*nn)->next =current->next;
                 current->next= *nn;
                 (*nn)->prev = current;
                 found = 1;
                 break;
             }

             else if((*nn)->key == current->next->key){
                 //printf("found same %d\n", current->key);
                 current->next->count++;
                 found = 1;
                 break;
             }
             current = current->next;
        }

         if(!found){
             current->next = *nn;
             (*nn)->prev = current;
             (*nn)->next = NULL;

         }
     }

 }

//--------------------------------------------------------------------------------------------------------------------------------------------------------
// A function to Delete a node from the list and free it.
 void DeleteNodeDLL(int value,nodeptr_t *head)
 {
     nodeptr_t walker = *head, delete;

     if(walker == NULL){
         printf("Cannot delete from empty list! \n");
         delete = NULL;
     }
     //Beginning
     else if(walker->key == value){
         if(walker->count >1){
             walker->count--;
             delete = *head;
         }
         else{
             delete = *head;
             delete->count--;
             (*head)=(*head)->next;
         }
     }
     //Middle / End
     else{
         while(walker != NULL && walker->key != value)
             walker = walker->next;

         if(walker == NULL){
             printf("Element not found! \n");
             delete = NULL;
         }
         else if(walker->key == value && walker->count > 1){
             walker->count--;
             delete = walker;
         }
         else if(walker->key == value && walker->count == 1){
             delete = walker;

             delete->count--;
             walker->prev->next = walker->next;

             if(walker->next != NULL)
                 walker->next->prev = walker->prev;
         }
     }

     return;}

//--------------------------------------------------------------------------------------------------------------------------------------------------------
// A function to Print the list in forward traversal order.
 void PrintListDLL(nodeptr_t *head){

     nodeptr_t w = *head;  // walker to traverse the list

     if(isEmpty(*head)){
         printf("List is empty.\n");}
     else{

         while (w != NULL) {
             printf("Key: %d Count: %d \n" ,w->key,w->count);
             w = w->next;}
     }
     printf("\n\n");
     return;
 }

//--------------------------------------------------------------------------------------------------------------------------------------------------------
// A function to compute the Length of the list.
 int LengthDLL(nodeptr_t *head) {

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
