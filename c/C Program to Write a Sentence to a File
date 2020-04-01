#include <stdio.h>
#include <stdlib.h>  /* For exit() function */
int main()
{
   char sentence[1000];
   FILE *fptr;

   fptr = fopen("program.txt", "w");
   if(fptr == NULL)
   {
      printf("Error!");
      exit(1);
   }
   
   printf("Enter a sentence:\n");
   gets(sentence);

   fprintf(fptr,"%s", sentence);
   fclose(fptr);

   return 0;
}
