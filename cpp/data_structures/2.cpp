#include<iostream>
using namespace std;
int main()
{
	int a[3][3],search,i,j;
	cout<<"Enter the 20 array elements of the array.\n";
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			cin>>a[i][j];
		}
	}
	cout<<"Enter the elements to search.\n";
	cin>>search;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			if(a[i][j]==search)
			{
				cout<<"The position of the element searched="<<i+1<<","<<j+1;
				break;
			}
		}
	}
	if(i==3)
	{
		if(j==3)
		{
			cout<<"Element is not in the array.\n";
		}
	}
	return 0;
}
