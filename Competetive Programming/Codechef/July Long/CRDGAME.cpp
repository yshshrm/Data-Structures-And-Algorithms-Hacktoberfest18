#include<bits/stdc++.h>
using namespace std;

int t, a, b, n, pointA, pointB;

int getSum(int n) {
    int sum;

    for (sum = 0; n > 0; sum += n % 10, n /= 10);

    return sum;
}

main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    scanf("%d", &t);
    while(t--){
        pointA = pointB = 0;
        scanf("%d", &n);
        while(n--){
            scanf("%d %d", &a, &b);
            if(getSum(a) > getSum(b))
                pointA++;
            else if(getSum(a) < getSum(b))
                pointB++;
            else{
                pointA++;
                pointB++;
            }
        }
        if(pointA > pointB)
            cout<<0<<" "<<pointA<<endl;
        else if(pointA < pointB)
            cout<<1<<" "<<pointB<<endl;
        else
            cout<<2<<" "<<pointA<<endl;
    }
    return 0;
}
