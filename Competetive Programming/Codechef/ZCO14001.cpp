#include<bits/stdc++.h>
using namespace std;

int n, i=0, flag = false;
long long h;

main(){
    cin>>n>>h;
    long long a[n];
    for(int i=0; i<n; i++)
        cin>>a[i];
    while(1){
        int c;
        cin>>c;
        switch(c){
            case 1:
                if(i!=0)
                    i--;
                break;
            case 2:
                if(i!=n-1)
                    i++;
                break;
            case 3:
                if(a[i] != 0 && flag == false){
                    a[i] = a[i] -1;
                    flag = true;
                }
                break;
            case 4:
                if(a[i] != h && flag == true){
                    a[i] = a[i] +1;
                    flag = false;
                }
                break;
            case 0:
                for(int i=0; i<n; i++)
                    cout<<a[i]<<" ";
                exit(0);
        }
    }
}
