#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



int main() {
	
    vector<int> vec;
    int n;
    cin>>n;
    vec.resize(n);
    for(int i=0;i<n;++i)
        cin>>vec[i];
    
    vector<int> LIS;
    
    for(int i=0;i<n;++i)
    {
        int idx = lower_bound(LIS.begin(),LIS.end(),vec[i]) - LIS.begin();
        
        if(idx==LIS.size())
            LIS.push_back(vec[i]);
        else
            LIS[idx] = vec[i];
    }
    
    cout<<LIS.size()<<endl;
	return 0;

}
