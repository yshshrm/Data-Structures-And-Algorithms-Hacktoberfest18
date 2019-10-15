#include <stdio.h>

int main(){
  int n, v[10000];
  scanf("%d", &n);
  for(int i = 0; i < n ;i++)
    scanf("%d", &v[i]);
  for(int i = 0; i < n; i++)
    for(int j = i+1; j < n; j++)
    {
      int aux = v[i];
      v[i] = v[j];
      v[j] = aux;
    }
  for(int i = 0; i < n; i++)
    printf("%d ", v[i]);
}
