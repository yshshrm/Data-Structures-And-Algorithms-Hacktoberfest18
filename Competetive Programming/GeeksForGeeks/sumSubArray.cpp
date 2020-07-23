#include<bits/stdc++.h>
using namespace std;

main(){
    int t;
    cin>>t;
    while(t--){
        int l,s, sum;
        bool flag= false;
        cin>>l>>s;
        int a[l];
        for(int i=0; i<l; i++){
            scanf("%d", &a[i]);
        }

        int i,j;
        for(i=0; i<l; i++){
            sum = a[i];
            for(j=i+1; j<=l; j++){
                if(sum == s){
                    cout<<i+1<<" "<<j<<endl;
                    flag = true;
                    break;
                } else if(sum >s || j==l){
                    break;
                } else{
                    sum = sum +a[j];
                }
            }
            if(flag) break;
        }
        if(!flag)
            cout<<-1<<endl;
    }
    return 0;
}
