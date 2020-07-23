#include<bits/stdc++.h>
using namespace std;

int t,n, temp, sum;
vector<int> vect;

main(){
    scanf("%d", &t);
    while(t--){
        vect.clear();
        sum=0;
        scanf("%d", &n);
        for(int i=0; i<n; i++){
            scanf("%d", &temp);
            vect.push_back(temp);
        }
        for(int i=0; i<n-1; i++){
            if(vect[i] == vect[i-1])
                sum+=0;
            else
                sum+=abs(vect[i]-vect[i+1])-1;
        }
        cout<<sum<<endl;
    }
}
