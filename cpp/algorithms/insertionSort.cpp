#include <iostream>

void insertionSort(int* vet, int tamanho){
  for(int i = 1; i<tamanho; i++){
    int j = vet[i];
    int k = i+1;
    while(--k>0 && vet[k-1] > j){
      vet[k] = vet[k-1];
    }
    vet[k] = j;
  }
}
