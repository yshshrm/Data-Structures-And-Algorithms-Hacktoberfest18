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
			time_elapsed=nextProcess.a_time+nextProcess.b_time;
			arrived.pop();
		}
		else
		{
			nextProcess=waiting.top();
			time_elapsed+=nextProcess.b_time;
			waiting.pop();	
		}
		ct[nextProcess.index]=time_elapsed;
		cout<<"Process :"<<nextProcess.a_time<<" "<<nextProcess.b_time<<endl;
		if(waiting.empty() && arrived.empty())
			break;
		
	}
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

