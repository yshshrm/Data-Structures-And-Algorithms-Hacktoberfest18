#include<iostream>
#include<queue>
#include<vector>
using namespace std;
struct process
{
	int index;
	int a_time;
	int b_time;
	process(int index,int a_time,int b_time)
	{
		this->index=index;
		this->a_time=a_time;
		this->b_time=b_time;
	}
	process()
	{}
};
struct compare1
{
	bool operator()(process p1,process p2)
	{
		if(p1.a_time == p2.a_time)
			return p1.b_time>=p2.b_time;
		return p1.a_time>=p2.a_time;
	}
};
struct compare2
{
	bool operator()(process p1,process p2)
	{
		return p1.b_time>=p2.b_time;
	}
};
int main()
{
	int n;
	cout<<"Enter the no. of processes"<<endl;
	cin>>n;
	int q;
	cout<<"Enter time quantum"<<endl;
	cin>>q;
	priority_queue<process,vector<process>,compare1>arrived;
	priority_queue<process,vector<process>,compare2>waiting;
	vector<int>ats(n);
	vector<int>bts(n);
	for(int i=0;i<n;i++)
	{
		int at,bt;
		cin>>at>>bt;
		arrived.push(process(i,at,bt));
		ats[i]=at;
		bts[i]=bt;
	}
	vector<int>ct(n);
	vector<int>wt(n);
	vector<int>tat(n);
	int time_elapsed=0;
	while(true)
	{
		process nextProcess;
		while(!arrived.empty() && arrived.top().a_time<=time_elapsed)
		{
			waiting.push(arrived.top());
			arrived.pop();
		}
		if(waiting.empty())
		{
			//means nothing within time elapsed.
			nextProcess=arrived.top();
			
			arrived.pop();
			if(nextProcess.b_time>q)
			{
				time_elapsed=nextProcess.a_time+q;
				nextProcess.b_time=nextProcess.b_time-q;
				waiting.push(nextProcess);
			}
			else
			{
				//process has finished execution
				time_elapsed=nextProcess.a_time+nextProcess.b_time;
				ct[nextProcess.index]=time_elapsed;
				cout<<"Finished process "<<nextProcess.index<<endl;
			}
		}
		else
		{
			nextProcess=waiting.top();
			
			waiting.pop();	
			if(nextProcess.b_time > q)
			{
				time_elapsed+=q;
				nextProcess.b_time=nextProcess.b_time-q;
				waiting.push(nextProcess);
			}
			else
			{
				//process has finished execution
				time_elapsed+=nextProcess.b_time;
				ct[nextProcess.index]=time_elapsed;
				cout<<"Finished process "<<nextProcess.index<<endl;
			}
		}
		
		if(waiting.empty() && arrived.empty())
			break;
		
	}
	cout<<endl;
	for(int i=0;i<n;i++)
		cout<<ct[i]<<" ";
	for(int i=0;i<n;i++)
		tat[i]=ct[i]-ats[i];
	double tot=0;
	//tot denotes total waiting time
	for(int i=0;i<n;i++)
	{
		wt[i]=tat[i]-bts[i];
		if(wt[i]<0)
			wt[i]=0;
		tot+=(wt[i]);
	}
	cout<<"Average waiting time is "<<tot/n<<endl;
	return 0;
}

