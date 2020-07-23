#include<bits/stdc++.h>
using namespace std;

main(){
    int t, num;
    scanf("%d", &t);
    while(t--){
        int count = 0;
        scanf("%d", &num);
        for(int i=5; num/i>=1; i=i*5){
            count = count + num/i;
        }
        cout<<count<<endl;
    }
    return 0;
}
