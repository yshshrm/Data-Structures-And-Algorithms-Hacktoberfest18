#include <iostream>

using namespace std;

struct Heap{
    int *arr;
    int size;

    Heap(int n){
        this->size = 0;
        arr = new int[n+1];
    }

    void insert(int x){
        arr[++size] = x;
        heapify(arr,size);
    }

    void heapify(int arr[],int size){
        if(size/2 < 1) return;
        int temp = size/2;
        int x = size;
        while(temp && arr[x]>arr[temp]){
            int t = arr[temp];
            arr[temp] = arr[x];
            arr[x] = t;
            x = temp;
            temp /= 2;
        }
    }

    void heapifyDown(int arr[],int size){
        int x = 1;
        int sw = 2 * x;
        while(sw <= size ){
            if(sw+1 <= size && arr[sw+1] > arr[sw]){
                sw++;
            }
            if(arr[sw] < arr[x])
                break;
            int temp = arr[sw];
            arr[sw] = arr[x];
            arr[x] = temp;
            x = sw;
            sw = 2 * x;
        }
    }

    void print(){
        cout<<"Heap is \n";
        for(int i=1;i<=size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

    void heapsort(){
        int *oarr = new int[size+1];
        for(int i=1;i<=size;i++){
            oarr[i] = arr[i];
        }
        int tsize = size;
        for(int i=1;i<size;i++){
            int temp = oarr[1];
            oarr[1] = oarr[tsize];
            oarr[tsize--] = temp;
            heapifyDown(oarr,tsize);
        }
        cout<<"Sorted array is: \n";
        for(int i=1;i<=size;i++){
            cout<<oarr[i]<<" ";
        }
        cout<<endl;
    }
};

int main(){
    int n;
    cout<<"Enter no. \n";
    cin>>n;
    Heap heap(n);
    cout<<"Enter elems \n";
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        heap.insert(x);
    }
    heap.print();
    heap.heapsort();
}