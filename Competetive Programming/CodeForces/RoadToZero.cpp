#include<bits/stdc++.h>
using namespace std;

main(){
    int t;
    scanf("%d", &t);
    while(t--){
        long long x, y, a, b, sx, sy, total;
        cin>>x>>y;
        cin>>a>>b;

        sx = abs(x-0);
        sy = abs(y-0);

        if(sx<sy){
            if(2*a<b){
                total = a*sx;
                x -=sx;
            }else{
                total = b*sx;
                x -=sx;
                y -=sx;
            }
        } else{
            if(2*a<b){
                total = a*sy;
                y -= sy;
            }else{
                total = b*sy;
                x -= sy;
                y -= sy;
            }
        }
        total = total + a*x +a*y;

        cout<<total<<endl;
    }
    return 0;
}
