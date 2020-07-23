#include<stdio.h>
void f (int n)
{
  if (n <=1)  {
   printf ("%d", n);
  }
  else {
   f (n/2);
   printf ("%d", n%2);
  }
}

main(){
    f(173);
    return 0;
}
