#include<iostream>
#include<string.h>
using namespace std;

void search(char* pat,char* txt){

    int n = strlen(txt);
    int m = strlen(pat);


    for(int i=0;i<=n-m;i++){
        int j=0;
        for( j=0;j<m;j++){
            if(txt[i+j]!=pat[j]){
                break;
            }
        }
        if(j==m){
            cout<<"Match found at:"<<i;
        }
    }

}


int main(){
     char txt[] = "AABAACAADAABAAABAA";
     char pat[] = "AABA";
     search(pat, txt);

}
