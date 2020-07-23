#include<bits/stdc++.h>
using namespace std;

vector<int> vect;
int t;

main(){
    scanf("%d", &t);
    int x;
    for(int i=0; i<t; i++){
        scanf("%d", &x);
        vect.push_back(x);
    }
    sort(vect.begin(), vect.end());

    for(int i=0; i<t; i++){
        cout<<vect[i]<<"\n";
    }
}
