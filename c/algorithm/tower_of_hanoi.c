#include <stdio.h>
void move(int n, char a, char c);
void TowerOfHanoi(int n, char a, char c, char b);
void move(int n, char a, char c){
       printf("Move disk # %d from peg %c to peg %c \n", n, a, c);
       return;
}
void TowerOfHanoi(int n, char a, char c, char b){
       if (n==1) move(1, a, c);
       else{
            TowerOfHanoi(n-1, a, b, c);
            move(n, a, c);
            TowerOfHanoi(n-1, b, c,a);
       }
       return;
}
int main(){
       int DiskNo;
       printf("Number of disks: ");
       scanf("%d",&DiskNo);
       TowerOfHanoi(DiskNo, 'a', 'c', 'b');
       return 0;
}

