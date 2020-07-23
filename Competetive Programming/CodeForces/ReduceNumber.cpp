#include <bits/stdc++.h>

using namespace std;

int countways(int n)
{
	if (n == 1)
		return 0;
    else if (n<1)
        return -1;
	else if (n % 6 == 0)
		return 1 + countways(n / 6);
	else
		return 1 + countways(n * 2);
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        cin>>n;
        int x = countways(n);
        if(x>n)
            cout<<-1<<endl;
        else
            cout <<x<< "\n";
    }
	return 0;
}

