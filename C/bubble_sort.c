/* bubble_sort implementation in C - github.com/jfstn */
#include <stdio.h>
#include <stdlib.h>

//void bubble_sort(int[], int);

int main(){
    int size;

    printf("Bubble Sort - C\n");
    printf("Enter the number of elements:\n");
    scanf("%d", &size);

    // array inicialization with random numbers
    int array[size], i;

    printf("Your random elements:\n");
    for (i = 0; i < size; i++){
        array[i] = rand() % 1000;
        printf("> %d <", array[i]);
    }

    // bubble sort
    int j, swap;

    for (i = 0; i < (size - 1); i++){
        for (j = 0; j < size - i - 1; j++){
            if (array[j] > array[j + 1]){
                swap = array[j];
                array[j] = array[j + 1];
                array[j + 1] = swap;
            }
        }
    }

    printf("\nSorted elements:\n");
    for (i = 0; i < size; i++){
        printf("> %d <", array[i]);
    }
}