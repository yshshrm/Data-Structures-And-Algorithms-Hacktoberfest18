#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int n,q;
	//n - no. of processes
	//q - time quantum
	cout<<"Enter the no. of processes"<<endl;
	cin>>n;
	cout<<"Enter time quantum"<<endl;
	cin>>q;
	vector<int>a(n);
	vector<int>b(n);
	vector<int>wt(n);
	for(int i=0;i<n;i++)
	{
		cout<<"Enter burst time"<<endl;
		cin>>a[i];
		b[i]=a[i];
	}
	int tot=0;
	while(true)
	{
		bool flag=false;
		for(int i=0;i<n;i++)
		{
			
			if(a[i]==0)
				continue;
			if(a[i]>q)
			{
				a[i]=a[i]-q;
				tot+=q;
				flag=true;
			}
			else
			{
				tot+=a[i];
				a[i]=0;
				wt[i]=tot-b[i];
				cout<<"Process "<<i<<" finished"<<endl;
			}
		}
		if(flag==false)
			break;
	}
	return 0;
}