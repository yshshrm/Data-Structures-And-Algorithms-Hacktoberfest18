
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node *nodeptr_t;


/*------------------------Function Prototypes-------------------------*/

// A function to check if the head is empty or not
bool isEmpty(nodeptr_t head);

// A function to Create the node and initializes information in it: key and count
nodeptr_t CreateNodeSLL(int key_value, nodeptr_t * head);

// A function to Insert a node, keeping the list in sorted order. It assumes the node has been created and is passed as an argument.
void InsertListSLL(nodeptr_t nn, nodeptr_t *head);

// A function to Delete a node from the list and free it.
void DeleteNodeSLL(int key_value, nodeptr_t *head);

// A function to Print the list.
void PrintListSLL(nodeptr_t *head);

// A function to compute the Length of the list.
int LengthSLL(nodeptr_t *head);

