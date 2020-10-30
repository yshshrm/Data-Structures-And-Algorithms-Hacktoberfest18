#include<bits/stdc++.h>
using namespace std;

void towerOfHanoi(int s,int h, int d, int n)
{
    if(n==1)
    {
        cout << "move disk " <<  n << " from rod " << s << " to rod " <<  d << "\n";
        return;
    }
    towerOfHanoi(s,d,h,n-1);
    cout << "move disk " <<  n << " from rod " << s << " to rod " <<  d << "\n";
    towerOfHanoi(h,s,d,n);
    return;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int s = 1, h = 2, d = 3;
        towerOfHanoi(s,h,d,n);
    }
	return 0;
}
