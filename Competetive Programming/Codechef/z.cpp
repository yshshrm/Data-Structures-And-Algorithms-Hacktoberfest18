#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int t;
	scanf("%d", &t);
	while(t--){
		int n, gcd=0;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		{
			for (int j = i+1; j <= n; j=j/i)
			{
				gcd = max(gcd, __gcd(i,j));
			}
		}
		cout<<gcd<<endl;
	}

}
