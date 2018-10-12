#include<iostream>
using namespace std;
void swap(int *x, int *y){
int temp;
temp=*x;
*x=*y;
*y=temp;
}

int main(){
int arr[7]={8,7,5,2,4,6,9};
int min1=0;
for(int i=0;i<6;i++){
int min=i;
  for(int j=i+1;j<7;j++){
    if(arr[j]<arr[min]){
     min=j;
}

}
swap(&arr[i],&arr[min]);


}
for(int i=0; i<7;i++){

    cout<<arr[i]<<endl;
}

return 0;
}
