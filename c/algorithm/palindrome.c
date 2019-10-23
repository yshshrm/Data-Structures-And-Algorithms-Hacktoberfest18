#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
bool isPalindrome(char* test){
   for(int i = 0; i < strlen(test)/2; i++){
      if(test[i] != test[strlen(test)-i-1]){
         return false;
      }
   }
   return true;
}


int main(){
   char* test = (char*) malloc(sizeof(char)*1000);
   scanf("%s", test);

   if(test){
      printf("Is a palindrome\n");
   }
   else{
      printf("Not a palindrome\n");
   }
}
