#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct process
{
	int priority;
	int b_time;
	int id;
	process(int id,int priority,int b_time)
	{
		this->id=id;
		this->priority=priority;
		this->b_time=b_time;
	}
	process()
	{}
};
bool compare(process p1,process p2)
{
	if(p1.priority==p2.priority)
		return p1.b_time<=p2.b_time;
	return p1.priority>=p2.priority;
}
int main()
{
	int n;
	cout<<"Enter the no. of processes"<<endl;
	cin>>n;
	vector<int>ct(n);
	vector<int>wt(n);
	vector<process>parr;
	for(int i=0;i<n;i++)
	{
		int p,b;
		cin>>p>>b;
		parr.push_back(process(i,p,b));
	}
	sort(parr.begin(), parr.end(),compare);
	double tot=0;
	for(int i=0;i<n;i++)
	{
		tot+=parr[i].b_time;
		ct[parr[i].id]=tot;
	}
	double wtime=0;
	for(int i=0;i<n;i++)
	{
		wt[parr[i].id]=ct[parr[i].id]-parr[i].b_time;
		wtime+=wt[parr[i].id];
	}
	cout<<"Average waiting time is "<<wtime/n;
}