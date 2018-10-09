#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>


int main()
{
 pid_t p1;
 p1 = fork();

 if(p1<0)
 {
    fprintf(stderr,"fork failed");
    return 0;
 }
 else if(p1==0)
 {
    printf("child process pid %d  parent process pid %d ",getpid(),getppid());
 }
 else{
     printf("child process pid %d  parent process pid %d",getpid(),getppid());
}
}
