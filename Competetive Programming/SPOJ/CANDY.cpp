#include<bits/stdc++.h>
using namespace std;

main(){
    vector<int> candy;
    while(true){
        candy.clear();
        int N, sum=0, ans=0;
        cin>>N;
        if(N==-1) break;
        for(int i=0; i<N; i++){
            int x;
            scanf("%d", &x);
            candy.push_back(x);
            sum = sum+candy[i];
        }
        if(sum%N!=0){
            cout<<-1<<endl;
        } else {
            int even = sum/N;
            for(int i=0;i<N;i++)
             {
                 if(even>candy[i])
                    ans+=even-candy[i];
            }

            cout<<ans<<endl;
        }
    }
    return 0;
}
