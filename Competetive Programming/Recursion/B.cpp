#include<bits/stdc++.h>
using namespace std;

main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n,countx=0;
        scanf("%d", &n);
        int arr[n];
        for(int i=0; i<n; i++){
            scanf("%d", &arr[i]);
        }
        for(int i=0; i<n; i++){
            if((i%2) == (arr[i]%2)){
                //cout<<0<<endl;
                break;
            }
            else{
                for(int j=i+1; j<n; j++){
                    if((j%2) != (arr[j]%2)){
                        swap(arr[i], arr[j]);
                        countx++;
                        i++;
                        break;
                    }
                }
                if(countx==0)
                    countx=-1;
            }
        }
        cout<<countx<<endl;
    }
}
