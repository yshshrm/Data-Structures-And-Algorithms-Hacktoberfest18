#include iostream
 
using namespace std;
 
void quick_sort(int[],int,int);
int partition(int[],int,int);
 

 
void quick_sort(int a[],int l,int u)
{
    int j;
    if(lu)
    {
        j=partition(a,l,u);
        quick_sort(a,l,j-1);
        quick_sort(a,j+1,u);
    }
}
 
int partition(int a[],int l,int u)
{
    int v,i,j,temp;
    v=a[l];
    i=l;
    j=u+1;
    
    do
    {
        do
            i++;
            
        while(a[i]v&&i=u);
        
        do
            j--;
        while(va[j]);
        
        if(ij)
        {
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }while(ij);
    
    a[l]=a[j];
    a[j]=v;
    
    return(j);
}

int main()
{
    int a[50],n,i;
    coutHow many elements;
    cinn;
    coutnEnter array elements;
    
    for(i=0;in;i++)
        cina[i];
        
    quick_sort(a,0,n-1);
    coutnArray after sorting;
    
    for(i=0;in;i++)
        couta[i] ;
    
    return 0;        
}