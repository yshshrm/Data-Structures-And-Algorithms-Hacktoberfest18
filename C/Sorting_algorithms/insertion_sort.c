#include<stdio.h>
 
int main() {
   int i, j, num, temp, arr[1000];
 
   printf("Enter total elements: ");
   scanf("%d", &num);
 
   printf("Enter %d elements: ", num);
   for (i = 0; i < num; i++) {
      scanf("%d", &arr[i]);
   }
 
   for (i = 1; i < num; i++) {
      temp = arr[i];
      j = i - 1;
      while ((temp < arr[j]) && (j >= 0)) {
         arr[j + 1] = arr[j];
         j = j - 1;
      }
      arr[j + 1] = temp;
   }
 
   printf("After Sorting: ");
   for (i = 0; i < num; i++) {
      printf("%d ", arr[i]);
   }
 
   return 0;
}
