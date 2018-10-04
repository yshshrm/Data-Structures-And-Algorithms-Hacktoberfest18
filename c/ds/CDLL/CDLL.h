#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

// must define ABREV:  It should also print the same information to a text file called ABBREVlogfile.txt, so as to track what the program did even if the output scrolls of the top of the screen;


typedef struct node * nodeptr_t;


//------------------------Function Prototypes-------------------------

// A function to check if the head is empty or not
bool isEmpty(nodeptr_t head);

// A function to Create the node and initializes information in it: key and count
nodeptr_t CreateNodeCDLL(int key_value);

// A function to Insert a node, keeping the list in sorted order. It assumes the node has been created and is passed as an argument.
void InsertListCDLL(nodeptr_t *nn, nodeptr_t *head);

// A function to Delete a node from the list and free it.
void DeleteNodeCDLL(int value,nodeptr_t *head);

// A function to Print the list.
void PrintListCDLL(nodeptr_t *head);

// A function to compute the Length of the list.
int LengthCDLL(nodeptr_t *head);
