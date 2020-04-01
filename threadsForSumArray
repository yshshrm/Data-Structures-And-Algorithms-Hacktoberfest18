#include<stdio.h>
#include<pthread.h>
#define SIZE 1000
#define THREADS 2

int a[SIZE];
int sum = 0;
int wload; 
pthread_mutex_t mylock;

void *sum_array(void *id){
    int low, high, result, myid;
    
    result = 0;
    low = (int) id * wload;
    high = low + wload;
    
    for(int i=low; i<high; i++){
    	result +=a[i];
	}

	pthread_mutex_lock(&mylock);
	sum+=result;
	pthread_mutex_unlock(&mylock);
}


main(){
	
	pthread_t tid[THREADS];
	wload=SIZE/THREADS;
    pthread_mutex_init(&mylock, NULL);
    printf("start of main\n");
    
    for(int i=0; i<SIZE; i++) a[i]=i+1;

	
	for(int i=0; i<THREADS; i++){
		pthread_create(&tid[i], NULL, sum_array,(void *)i);
		
	}
	
	for(int i=0; i<THREADS; i++){
		pthread_join(tid[i], NULL);
	}

    printf("\nend of main %d\n", sum);
}


