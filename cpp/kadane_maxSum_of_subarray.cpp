#include<cstdio>
#define max(a, b)((a)>(b)?(a):(b))

int main(){
    int n,i;
    scanf("%d", &n);
    int a[n];
    for(i=0;i<n;i++){
        scanf("%d", &a[i]);
    }
    int tot_max = a[0];
    int cur_max = a[0];
    for(i=1;i<n;i++){
        cur_max = max(a[i], cur_max+a[i]);
        tot_max = max(cur_max, tot_max);
    }
    printf("%d", tot_max);
    return 0;
}
