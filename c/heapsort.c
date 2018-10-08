#include<stdio.h> int left(int i)
{
return 2*i+1;
}
int right(int i)
{
return 2*i+2;
}
void max_heapify(int *,int,int); void build_maxheap(int *a,int n)
{
int i;
for(i=(n-1)/2;i>=0;i--){ max_heapify(a,i,n);
}
}
void max_heapify(int *a,int i,int n) {
int largest,temp;
int l=left(i);
int r=right(i);
if(l<=n-1 && a[l]>a[i]){

largest=l;
}
else{
largest=i;
}
if(r<=n-1 && a[r]>a[largest]){ largest=r;
}
if(largest!=i){
temp=a[i];
a[i]=a[largest];
a[largest]=temp; max_heapify(a,largest,n);
}
}
int main()
{
int a[100],i,k,n,temp;
printf(“Enter number of elements”); scanf(“%d”,&n);
printf(“Enter elements “); for(i=0;i<n;i++){
scanf(“%d”,&a[i]);
}
build_maxheap(a,n); for(i=n-1;i>0;i--)
{
temp=a[0];
a[0]=a[i];
a[i]=temp; printf(“Pass %d: “,n-i); for(k=0;k<n;k++) printf(“%d “,a[k]); printf(“\n”); max_heapify(a,0,i);
}
printf(“Sorted array “); for(i=0;i<n;i++){ printf(“%d “,a[i]);
}
return 0;
}
