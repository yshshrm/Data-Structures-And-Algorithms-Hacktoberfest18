#include<stdio.h>
int main(void)
{int x,y,p,pow=1;
scanf("%d %d %d",&x,&y,&p);
while(y>0){
if(y%2!=0)
pow=(pow*x)%p;

y/=2;
x=(x*x)%p;

}
printf("%d",pow);
return 0;
}
