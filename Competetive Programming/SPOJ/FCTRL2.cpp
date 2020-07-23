#include<bits/stdc++.h>
using namespace std;

main(){
    int t, num;
    scanf("%d", &t);
    while(t--){
        int fact=1;
        scanf("%d", &num);
        for(int i=num; i>=1; i--){
            fact = fact*i;
        }
        cout<<fact<<endl;
    }
    return 0;
}
