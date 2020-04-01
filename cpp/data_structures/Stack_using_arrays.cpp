#include<iostream.h>
#include<conio.h>
void push();
void pop();
void dis();

int top=-1,ar[10],n=10;

void main()
{
  int ch;

  do{
	cout<<"SELECT AN OPTION : \n\n";
	cout<<"1. ENTER AN ELEMENT\n";
	cout<<"2. DELETE AN ELEMENT\n";
	cout<<"3. DISPLAY THE ELEMENTS\n";
	cout<<"4. EXIT\n";
	cin>>ch;

	switch(ch)
	{
		case 1 : {push();
		break;}
		case 2 : {pop();
		break;}
		case 3 :  {dis();
		break;}
		case 4 : break;
		default : {cout<<"WRONG OPTION!!\n";
		break;}
	}
  }while(ch!=4);
}

void push()
{
   if(top >= n-1)
   {
      cout<<"Stack Overflow.\n";
   }
   else
   {
      top++;
      cout<<"Enter the element : ";
      cin>>ar[top];
   }
}

void pop()
{
   if(top <= -1)
   {
      cout<<"Stack Underflow.\n";
   }
   else
   {
      cout<<"Element deleted: "<<ar[top];
      top--;
   }

}

void dis()
{
  if(top>=0)
  {
     cout<<"Elements are :\n";
     for(int i=top;i>=0;i--)
     {
      cout<<ar[i]<<"\n";
     }
   }
   else
   {
      cout<<"Stack is empty.\n";
   }
}