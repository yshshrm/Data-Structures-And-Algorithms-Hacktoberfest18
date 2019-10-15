#include<stdio.h> 
#define N 10 
  
int main(int num) 
{ 
    if (num <= N && printf("%d ", num) && main(num + 1)) 
    { 
    }      
} 