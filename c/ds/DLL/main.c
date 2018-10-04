// Author: Inès Benomar
//
// Input Files: none, interactive program
// Output Files: none, interactive program


#include <stdio.h>
#include <stdlib.h>
#include "DLL.h"



int main(void) {
    int N;
    int i,length_var, n;
    int rand_nbrs[20];
    FILE * bptr1;
    FILE * bptr3;
    FILE* bptr5;
    FILE * bptr4;

    /* Declare variable head of type nodeptr_t */
    nodeptr_t head = NULL, newnode;

    /*
     1. Generates N random integers between 0 and 9 and stores them in a binary file called insert.bin.
     It should let the user know what numbers were generated and written. */

    // Getting input from user
    printf(" Please enter an N value —it should be larger than 10 but should not exceed 20: ");
    scanf("%d", &N);


    bptr1 = fopen("insert.bin","wb"); //overwriting
    if (bptr1==NULL)
        perror("Error opening file: ");
    else{
        printf("Numbers generated:\n");
        for(i=0;i<N;i++){
            n = rand() % 10;
            printf(" %d ",n);
            fwrite(&n,sizeof(int),1,bptr1);
        }
        printf("\n");
        fclose(bptr1);
    }


    /*
     2. then generates another N random integers between 0 and 9 and stores them in another binary file called delete.bin.
     It should let the user know what numbers were generated and written. */

    // Getting input from user

    // Generating N random integers using rand()

    bptr3 = fopen("delete.bin","wb");
    if (bptr3==NULL) perror("Error opening file: ");

    else{
        printf("Numbers generated for delete:\n");
        for(i=0;i<N;i++){
            n = rand() % 10;
            printf(" %d ",n);
            fwrite(&n,sizeof(int),1,bptr3);
        }
            printf("\n");
            fclose(bptr3);
    }


//--------------------------------------------------------------Doubly Linked Lists-----------------------------------------------------------------------

    /*
     3. Inserting in linked lists
     */

    // reading insert.bin one int at a time

    bptr5 = fopen("insert.bin","rb");
    if (bptr5==NULL) perror("Error opening file: ");

    else{
        for(i=0;i<N;i++){
            fread(&n,sizeof(int),1, bptr5);

            //display value read from file
            printf("Value inserted: %d \n",n);

            //add value in the lists + store it in key member + keep list sorted in inc order
            newnode = CreateNodeDLL(n);
            InsertListDLL(&newnode,&head);

            //display length & contents of list with new value inserted

            //NEEd a function that traverses the list and changes the count variable if a number occurs more than once

        }
        length_var =LengthDLL(&head);
        printf("Length of the list is: %d \n",length_var);
        printf("List Status: \n");
        PrintListDLL(&head);

    }fclose(bptr5);

    /*
     4. Deleting from linked lists
     */

    // reading insert.bin one int at a time

    bptr4 = fopen("delete.bin","rb");
    if (bptr4==NULL) perror("Error opening file: ");

    else{
        for(i=0;i<=N;i++){
            //display value read from file
            fread(&n,sizeof(int),1, bptr4);
            printf("Value: %d\n",n);

            //deleting that value from each of the linked lists.
            DeleteNodeDLL(n,&head);

            //display length & contents of list with new value deleted
            length_var = LengthDLL(&head);
            printf("Length of the list is: %d \n",length_var);
            PrintListDLL(&head);
            printf("List Status: \n");

        }
    }



  return 0;}
