#include<bits/stdc++.h>
using namespace std;

int m,x,y;
int a[11];

main(){
    int t;
    cin>>t;
    while(t--){
        int safeHouse =0;
        cin>>m>>x>>y;
        for(int i=0; i<m; i++)
            cin>>a[i];
        int unsafe = x*y;

        for(int i=0; i<m-1; i++){
            if((a[i+1]-unsafe)- (a[i]+unsafe)-1 <= 0)
                safeHouse = 0;
            else
                safeHouse += ((a[i+1]-unsafe)- (a[i]+unsafe)-1);
        }
        safeHouse += (100-(*max_element(a, a+m)+unsafe));
        if(safeHouse>=0)
            cout<<safeHouse<<endl;
        else
            cout<<0<<endl;
    }
    return 0;
}
