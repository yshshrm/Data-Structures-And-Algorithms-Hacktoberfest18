/*TO SORT A DYNAMICALLY ALLOCATED ARRAY IN ASCENDING ORDER */
#include<iostream.h>
#include<conio.h>
 void arrange(int *p)
{
   for(i=0;i<n;i++)
   {
    for(j=0;j<n-1;j++)
     {
      if(*(p+j)>*(p+j+1))
       {
        t=*(p+j);
        *(p+j)=*(p+j+1);
        *(p+j+1)=t;
       }
     }
   }
}
 
void main()
{
  clrscr();
  int n,i,*p,j,t;
  cout<<"enter the value of n :";
  cin>>n;                   
  p=new int[n];    //dynamically allocation
  for(i=0;i<n;i++)//enter values in array
    {
     cin>>*(p+i);
    }
  cout<<"\n\n";
  arrange(*p);
  cout<<"\n\nascending order is : "<<"\n";
  for(i=0;i<n;i++)
  {
    cout<<*(p+i)<<"  ";
  }
  delete []p;  //deleting allocated memory
  getch();
}

