int MissingNumber(int arr[], int size){
  int k=0,sum=0;
  for(int i=0;i<size;i++)
    sum+=arr[i];
  k=((size-1)*(size-2))/2;
  return sum - k;

