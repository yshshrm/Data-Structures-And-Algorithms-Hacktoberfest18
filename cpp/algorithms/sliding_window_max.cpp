#include <bits/stdc++.h>
using namespace std;

vector<int> slidingMaximum(vector<int> &A, int B) 
{
    int n=A.size();
    vector<int> sol;
    deque<int> dq;
    for(int i=0;i<B;i++)
    {
        while(!dq.empty()&&A[dq.back()]<A[i]) dq.pop_back();
        dq.push_back(i);
    }
    sol.push_back(A[dq.front()]);
    for(int i=B;i<n;i++)
    {
        // remove elements not part of current window from the front
        //sol.push_back(A[dq.front()]);// return max element of previous window
        while(!dq.empty()&&dq.front()<=i-B) dq.pop_front();
        while(!dq.empty()&&A[dq.back()]<A[i]) dq.pop_back();
        dq.push_back(i); sol.push_back(A[dq.front()]);
    }
    // sol.push_back(A[dq.front()]); // max element of last window
    return sol;
}

int main() 
{ 
    vector<int> A;
    int n; cin>>n; // Input array size
    for(int i=0;i<n;i++)
    {
        int x; cin>>x;
        A.push_back(x);
    } 
    int k; cin>>k; // Input window size 
    
    vector<int> sol=slidingMaximum(A,k);
    for(int i=0;i<sol.size();i++) cout<<sol[i]<<" ";
    cout<<endl; 
    return 0; 
} 