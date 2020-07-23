#include <bits/stdc++.h>
using namespace std;

int main() {
    int X;
    float balance;
    cin>>X>>balance;
    if(X%5==0)
        {
          if(X+0.5<balance)
          {
            cout<<fixed << setprecision(2) <<balance-X-0.5;
          }
          else
          {
              cout<<fixed << setprecision(2)<<balance;
          }
        }
    else{
        cout<<fixed << setprecision(2)<<balance;
    }
	return 0;
}
