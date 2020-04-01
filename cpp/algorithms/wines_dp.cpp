/// Given an array of wines find the max profit the seller can earn if he sells the wines at a price day*wines[i]
/// It is given the seller can choose only from the extreme ends
#include<iostream>
using namespace std;

int maxProfitWines(int *wines,int i,int j,int day,int table[][10]){
    ///Base Case
        if(i>j){
            return 0;
        }
    if(table[i][j]==0){
    ///Rec Case
        int profit = 0;
        int op1 = day*wines[i] + maxProfitWines(wines,i+1,j,day+1,table);
        int op2 = day*wines[j] + maxProfitWines(wines,i,j-1,day+1,table);
        table[i][j] = max(op1,op2);
    }
    return table[i][j];

}


int main(){
    int wines[] = {2,3,5,1,4};
    int n= 5;
    int table[10][10] = {0};
    cout<<maxProfitWines(wines,0,n-1,1,table);




return 0;
}
