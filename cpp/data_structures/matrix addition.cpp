#include<iostream>
using namespace std;
int main()
{
	int a[3][3],b[3][3],s[3][3],i,j;
	cout<<"Enter the elements of the matrix array 1.\n";
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			cin>>a[i][j];
		}
	}
	cout<<"Enter the elements of the matrix array 2.\n";
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			cin>>b[i][j];
		}
	}
	cout<<"addition of matrix.\n";
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			s[i][j]=a[i][j]+b[i][j];
			cout<<s[i][j]<<"\n";
		}
	}
	return 0;
}
