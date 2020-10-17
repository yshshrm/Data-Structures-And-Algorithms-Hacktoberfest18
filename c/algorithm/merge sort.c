void merge(int a[],int l,int m,int u)
{
	int i,j,n1,n2,k;
	
    n1=m-l+1;
	n2=u-m;
	
    int a1[n1],a2[n2];

	for(i=0;i<n1;i++)
		a1[i]=a[i+l];

	for(i=0;i<n2;i++)
		a2[i]=a[n1+i];

	i=j=k=0;

	while (i < n1 && j < n2)
    {
        if (a1[i] <= a2[j]) a[k] = a1[i++];
        else a[k] = a2[j++];
       
        k++;
    }

    while (i < n1) a[k++] = a1[i++];

    while (j < n2) a[k++] = a2[j++];

}

void merge_sort(int a[],int l,int u)
{
	int m;
	if(l<u)
	{
		m = (u+l)/2;

		merge_sort(a,l,m);
		merge_sort(a,(m+1),u);
        merge(a,l,m,u);
		
	}

}
