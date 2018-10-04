// Author: Inès Benomar
//
// Input Files: none, interactive program
// Output Files: none, interactive program



#include <stdio.h>
#include <stdlib.h>
#include "CDLL.h"

int main(void) {
    int N;
    int i,length_var;
    int rand_nbrs[20];
    FILE* bptr4;
    FILE * bptr1;
    FILE* bptr2;
    FILE * bptr3;

    /* Declare variable head of type nodeptr_t */
    nodeptr_t head = NULL, newnode;

    /*
     1. Generates N random integers between 0 and 9 and stores them in a binary file called insert.bin.
     It should let the user know what numbers were generated and written. */

    // Getting input from user
    printf(" Please enter an N value —it should be larger than 10 but should not exceed 20: ");
    scanf("%d", &N);

    // Generating N random integers using rand()
    for(i=0;i<N;i++){
        rand_nbrs[i]= rand() % 10;


        // storing random integers in binary file in insert.bin

        bptr1 = fopen("insert.bin","wb"); //overwriting
        if (bptr1==NULL) perror("Error opening file: ");

        else{fwrite(&rand_nbrs,sizeof(int),1,bptr1);}
        fclose(bptr1);}

    // reading binary file to let user know which numbers were generated and written in insert.bin

    bptr2 = fopen("insert.bin","rb");
    if (bptr2==NULL) perror("Error opening file: ");

    else{ fread(&rand_nbrs[i],sizeof(int),N, bptr2);
        printf("Numbers generated:\n");
        for(i=0;i<N;i++){
            printf(" %d ",rand_nbrs[i]);}
        printf("\n\n");
    }fclose(bptr2);

    /*
     2. then generates another N random integers between 0 and 9 and stores them in another binary file called delete.bin.
     It should let the user know what numbers were generated and written. */

    // Getting input from user
    printf(" Please enter an N value —it should be larger than 10 but should not exceed 20: ");
    scanf("%d", &N);

    // Generating N random integers using rand()
    for(i=0;i<N;i++){
        rand_nbrs[i]= rand() % 10;

        // storing random integers in binary file delete.bin

        bptr3 = fopen("delete.bin","wb");
        if (bptr3==NULL) perror("Error opening file: ");

        else{fwrite(&rand_nbrs[i],sizeof(int),1,bptr3);}
        fclose(bptr3);}

    // reading binary file to let user know which numbers were generated and written in delete.bin

    bptr4 = fopen("delete.bin","rb");
    if (bptr4==NULL) perror("Error opening file: ");

    else{ fread(rand_nbrs,sizeof(int),N, bptr4);
        printf("Numbers generated:\n");
        for(i=0;i<N;i++){
            printf(" %d ",rand_nbrs[i]);}
        printf("\n\n");
    }fclose(bptr4);

    //--------------------------------------------------Circular Doubly Linked Lists---------------------------------------------------------

    /*
     3. Inserting in linked lists
     */

    // reading insert.bin one int at a time
    bptr2 = fopen("insert.bin","rb");
    if (bptr2==NULL) perror("Error opening file: ");

    else{
        for(i=0;i<N;i++){
            fread(&rand_nbrs[i],sizeof(int),1, bptr2);

            //display value read from file
            printf("Value: %d\n",rand_nbrs[i]);

            //add value in the lists + store it in key member + keep list sorted in inc order
            newnode = CreateNodeCDLL(rand_nbrs[i]);
            InsertListCDLL(&newnode,&head);

            //display length & contents of list with new value inserted

            //NEEd a function that traverses the list and changes the count variable if a number occurs more than once

            length_var =LengthCDLL(&head);
            printf("Length of the list is: %d \n",length_var);
            printf("List Status: \n");
            PrintListCDLL(&head);}

    }fclose(bptr2);

    /*
     4. Deleting from linked lists
     */

    // reading insert.bin one int at a time
    bptr4 = fopen("delete.bin","rb");
    if (bptr4==NULL) perror("Error opening file: ");

    else{
        for(i=0;i<=N;i++){
            //display value read from file
            fread(&rand_nbrs[i],sizeof(int),1, bptr4);
            printf("Value: %d\n",rand_nbrs[i]);

            //deleting that value from each of the linked lists.
            DeleteNodeCDLL(rand_nbrs[i],&head);

            //display length & contents of list with new value deleted
            length_var =LengthCDLL(&head);
            printf("Length of the list is: %d \n",length_var);
            PrintListCDLL(&head);
            printf("List Status: \n");


        }
    }



    return 0;}
