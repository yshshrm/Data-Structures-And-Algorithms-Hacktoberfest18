#include <iostream>
using namespace std;

void bubbleSort(int * array, int size);
	
int main(){
	
	return 0;
}

void bubbleSort(int * array, int size){
    for(int i = 0; i < size - 1; i++){
        for(int j = 0; j < size - i - 1; j++){
            if(array[j+1] < array[j]){
                int tmp = array[j + 1];
                array[j + 1] = array[j];
                array[j] = tmp;
            }   
        }   
    }   
} 
