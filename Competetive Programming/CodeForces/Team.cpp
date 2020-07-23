#include<bits/stdc++.h>
using namespace std;

main(){
	int n, total=0;
	scanf("%d", &n);
	while(n--){
		int p,v,t,flag=0;
		scanf("%d %d %d", &p, &v, &t);
		if(p==1)
			flag++;
		if(v==1)
			flag++;
		if(t==1)
			flag++;

		if(flag>=2)
			total++;
	}
	cout<<total<<endl;
	return 0;
}