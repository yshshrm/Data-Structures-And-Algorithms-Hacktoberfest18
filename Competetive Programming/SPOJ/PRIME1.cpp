#include<bits/stdc++.h>
using namespace std;

void isPrime(int n){
    int flag=1;
    for(int i=2; i<=sqrt(n);i++){
        if(n%i==0){
            flag=0;
            break;
        }
    }
    if(flag==1)
        cout<<n<<endl;
}

main(){
    int t,m,n;
    scanf("%d", &t);
    while(t--){
        scanf("%d%d",&m,&n);
        for(int i=m; i<=n;i++){
            if(i==1 || i==0)
                continue;
            isPrime(i);
        }
    }
    return 0;
}
