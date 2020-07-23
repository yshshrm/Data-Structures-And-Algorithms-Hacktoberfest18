int findMissing(int arr[], int n){
	map<int,int> hm;

	for(int i=0;i<n;i++)
		if(arr[i]>0)
			hm[arr[i]]++;
	
	int j=1;
	for(auto &x:hm){
		if(x.first!=j)
			return j;
		j++;
	}	
	
	return n+1;
}