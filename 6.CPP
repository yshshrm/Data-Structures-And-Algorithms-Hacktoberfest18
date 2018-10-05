//Question 6
//Programmer: Ayush Jain
#include<iostream.h>
#include<conio.h>
class array
{
	int a[10];
	int n;
	public:
		void createarray();
		void showarray();
		void insertion_sort();
		void binary_search();
};
void array::createarray()
{
	cout<<"\nEnter Number Of Elements: ";
	cin>>n;
	cout<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<"\t"<<i+1<<".a{"<<i<<"}=";
		cin>>a[i];
	}
}
void array::showarray()
{
	for(int i=0; i<n;i++)
	{
		cout<<"\t"<<i+1<<".a["<<i<<"}="<<a[i]<<endl;
	}
}
void array::insertion_sort()
{
	int temp, j;
	for(int i=1;i<n;i++)
	{
		temp=a[i];
		j=i-1;
		while(temp<a[j]&&j>=0)
		{
			a[j+1]=a[j];
			j-- ;
		}
		a[j+1]=temp;
	}
}
void array::binary_search()
{
	insertion_sort();
	int val, mid, flag=0;
	cout<<"\nEnter Value To Be Searched: ";
	cin>>val;
	int L=0, U=n;
	do
	{
		mid=(L+U+1)/2;
		if(a[mid]==val)
		{
			flag++;
			break;
		}
		else
		{
			if(a[mid]>val)
				U=mid-1;
			else
				L=mid+1;
		}
	}while(L<U);
	if(flag==0)
		cout<<"\nValue Not Found"<<endl;
	else
		cout<<"\nIndex of value is: "<<mid<<endl;
}
void menu()
{
	cout<<"\n\t\t\t\tMAIN MENU"<<endl;
	cout<<"1.Create Array"<<endl;
	cout<<"2.Show Array"<<endl;
	cout<<"3.Insertion Sort"<<endl;
	cout<<"4.Binary Search"<<endl;
	cout<<"5.Exit"<<endl;
}
void main()
{
	clrscr();
	int opt;
	array x;
	do
	{
		menu();
		cout<<"\nEnter Option: ";
		cin>>opt;
		cout<<endl<<endl;
		switch(opt)
		{
			case 1:
				x.createarray();
				break;
			case 2:
				x.showarray();
				break;
			case 3:
				x.insertion_sort();
				x.showarray();
				break;
			case 4:
			       x.binary_search();
			       break;
			case 5:
				cout<<"\nBYE";
				break;
			default:
				cout<<"\nWrong Option"<<endl;
				break;
		}
		getch();
		}while(opt!=5);
	getch();
}
/*OUTPUT
2.Show Array
3.Insertion Sort
4.Binary Search
5.Exit

Enter Option: 4



Enter Value To Be Searched: 12

Index of value is: 3

				MAIN MENU
1.Create Array
2.Show Array
3.Insertion Sort
4.Binary Search
5.Exit

Enter Option: 5



BYE
*/