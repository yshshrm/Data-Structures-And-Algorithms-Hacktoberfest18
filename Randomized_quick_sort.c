#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int Random(int start, int end) {
    srand(time(0));
    return (rand() % (end - start + 1)) + start;
}

void swap(int *a, int *b) {

	int temp = *a;
	*a = *b;
	*b = temp;

}

void sort(int A[], int start, int end, int k) {

	if(start < end) {
		int p_index = Random(start, end), s_index = start, l_index = end;

		while(s_index <= l_index) {
		
			while(s_index <= end && A[s_index] <= A[p_index]) {
					s_index++;
			}
		
			while(l_index > p_index && A[l_index] >= A[p_index]) {
					l_index--;
			}
		
			if(s_index < l_index) {
				swap((A+s_index), (A+l_index));
			}
		}

		swap((A+p_index), (A+l_index));

		printf("The present Array is: \n\n");
		for(int i=0; i<k; i++) printf("%2d ",A[i]);
		printf("\n\n");

		sort(A, start, l_index-1, k);
		sort(A, l_index+1, end, k);
	}
}

int main() {

	int *A, k;

	printf("Enter the number of elements: \t");
	scanf("%d", &k);

	A = (int *) malloc (k * sizeof(int));

	printf("Enter your elements: \t");
	for(int i=0; i<k; i++) scanf("%d", A+i);

	printf("You entered: \n\n");
	for(int i=0; i<k; i++) printf("%2d ", A[i]);
	printf("\n\n");

	sort(A, 0, k-1, k);

	printf("The sorted Array is: \n\n");
	for(int i=0; i<k; i++) printf("%2d ",A[i]);
	printf("\n\n");

	return 0;
}
