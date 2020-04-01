#include<bits/stdc++.h>

using namespace std;
int main()
{
    int n;
    cout<<"Enter the number of jobs\n";
    cin>>n;
    int j[n];
    cout<<"enter the jobs Profit\n";
    for(int i=0;i<n;i++)
        cin>>j[i];
    int d[n];
    cout<<"Enter the deadlines of the jobs\n";
    for(int i=0;i<n;i++)
        cin>>d[i];
    //GEting the max element and creating the time slot
    int *limit=std::max_element(d,d+n); //for getting the max elemnt
    int timeSlot[*limit]={0};   //timeslot inintially 0
    for(int i=0;i<*limit;i++)
        cout<<timeSlot[i]<<" ";
    //main logic
    vector <int> jobsequence;   //Order of jobsequence
    for (int i = 0; i < n; i++)
    {
        int maxindex=distance(j, max_element(j, j + n));    //index of max element
        int startlimit=d[maxindex]-1;   //start limit for loop (wrt to deadline)
        cout<<"\nMax index element is "<<maxindex<<" Start limit is "<<startlimit;        
        for(int k=startlimit;k>=0;k--)
        {
            
            if(timeSlot[k]==0)
            {

                timeSlot[k]=1;
                jobsequence.push_back(maxindex);
                break;
            }
                
        }
        j[maxindex]=0;  //After use manke the max index 0
    }
    cout<<"Job sequencing is as follow:\n";
    
    for (auto i = jobsequence.begin(); i != jobsequence.end(); ++i) 
        cout << *i+1 << " "; 
    cout<<"\n";
}