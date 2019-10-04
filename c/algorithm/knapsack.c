#include<stdio.h>
struct element {
  int id;
  int profit;
  int weight;
  int ratio;
};
void main() {
  struct element knapsack[15], temp;
  int n, i,j, size=40;
  float solution_vector[15], total_profit=0.0;
  printf("the size of bag is 40\n");
  printf("enter number of elements in knapsack");
  scanf("%d",&n);
  printf("enter profit and weight \n");
  for(i=0 ;i < n ; i++) {
    knapsack[i].id = i;
    scanf("%d",&knapsack[i].profit);
    scanf("%d",&knapsack[i].weight);
    solution_vector[i] = 0.0;
    knapsack[i].ratio = (float)knapsack[i].profit / knapsack[i].weight;
  }
  for(i=0;i<n-1;i++){
    for(j=0;j<n-i-1;j++){
      if(knapsack[j].ratio>knapsack[j+1].ratio){
        temp=knapsack[j];
        knapsack[j]=knapsack[j+1];
        knapsack[j+1]=temp;
      }
    }
  }
  for(i=n-1; i >= 0; i--) {
    if(knapsack[i].weight <= size) {
      solution_vector[knapsack[i].id] = 1.0;
      size = size - knapsack[i].weight;
    }
    if(knapsack[i].weight > size) {
      if(size==0)
        break;
      solution_vector[knapsack[i].id] = (float)size / knapsack[i].weight;
      size = 0;
    }
  }
  printf("solution vector is: \n");
  for(i=0 ; i < n ; i++) {
    printf("%.2f\n",solution_vector[i]);
    total_profit += solution_vector[i]*knapsack[i].ratio;
  }
  printf("the total profit %f",total_profit);
}
