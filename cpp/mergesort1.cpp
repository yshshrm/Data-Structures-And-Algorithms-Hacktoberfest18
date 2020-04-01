void merge(int a[], int n, int b[], int m, int c[]);
  
 
void mergeSort(int input[], int size){
  
  if(size==1)
    return;
  
  int half=(size+1)/2;
  
  
  mergeSort(input,half);
  mergeSort(input+half,size-half);
  int temp[1000];
   merge(input,half,input+half,size-half,temp);
  for(int i=0;i<size;i++)
    input[i]=temp[i];
	
        
}
void merge(int a[], int n, int b[], int m, int c[]){
   

  int r1=0,r2=0,w=0;
 while(r1<n && r2<m)
    {
       if(a[r1]<=b[r2])
       {c[w++]=a[r1++];}
  else
  {c[w++]=b[r2++];}
 }
  
  while(r1<n)
  { c[w++]=a[r1++];}
  while(r2<m)
  {c[w++]=b[r2++];}
}

