#include<bits/stdc++.h>
using namespace std;

main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int N, sum=0;
        scanf("%d", &N);
        vector<int> men;
        vector<int> women;
        for(int i=0; i<N; i++){
            int x;
            cin>>x;
            men.push_back(x);
        }
        for(int i=0; i<N; i++){
            int x;
            cin>>x;
            women.push_back(x);
        }
        sort(men.begin(), men.end());
        sort(women.begin(), women.end());
        for(int i=0; i<N; i++){
            sum = sum + men[i]*women[i];
        }
        cout<<sum<<endl;
    }
    return 0;
}
