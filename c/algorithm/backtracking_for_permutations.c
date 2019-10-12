#include <stdio.h>
int a[20], n, used[20] = { 0 }; // Declaring the variables globally for convenience

void array_write(){
  for(int i = 1; i <= n; i++)
    printf("%d ", a[i]); // It will output the array and a new line
  printf("\n");
}

void backtrack(int k)
{
  for(int i = 1; i <= n; i++) // goes on each element from the 1  to  n
  {
    if(!used[i]){ // It checks if it's not used
        a[k] = i; 
        used[i] = 1; // The element is used
        if(k == n)
          array_write(); 
        else backtrack(k+1); // It goes on the next element
        used[i] = 0; // It frees the element
    }
  }
}

int main(){
  scanf("%d", &n);  // It only reads one variable
  backtrack(1); // 1 for the first element form the array
}
