#include <stdio.h>
#include <stdlib.h>
int a[10],n1=10,b[10],n2=9;
void create_heap(int j,int n){
	int c;
	b[j]=n;
	while(j>0){
		if ((b[(j-1)/2])<b[j]){
			c=b[j];
			b[j]=b[(j-1)/2];
			b[(j-1)/2]=c;
		}
		j=(j-1)/2;
	}
}
int heapify(){
	int j=0,c;
	while((2*j+1<n2)&&((b[j]<b[(2*j+1)])||(b[j]<b[(2*j+2)]))){
		if (b[(2*j+1)]>b[2*j+2]){
			c=b[j];
			b[j]=b[2*j+1];
			b[2*j+1]=c;
			j=2*j+1;
		}
		else{
			c=b[j];
			b[j]=b[2*j+2];
			b[2*j+2]=c;
			j=2*j+2;
		}
	}
	return b[0];
}
void main(){
	int i,d,m;
	for (i=0;i<n1;i++){
		scanf("%d",&a[i]);
		create_heap(i,a[i]);
	}
	for (i=0;i<n1;i++)
		printf("%d ",b[i]);
	d=n1;
	a[d-1]=heapify();
	for (i=n1-1;i>0;i--){
		m=b[i];
		b[i]=b[n2-i];
		b[n2-i]=m;
		n2--;
		a[i-1]=heapify();
	}
	printf("\n");
	for (i=0;i<n1;i++)
		printf("%d ",a[i]);
}