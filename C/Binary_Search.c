#include<stdio.h>

#define Maxtam 20

typedef struct Obj{
	int key; // ordered by key
	int num;
}Obj;
/*
returns the array indice
key must be ordered
*/
int BinSearch(Obj vec[], int key){
	int end=Maxtam-1,begin = 0, mid = (Maxtam-1)/2;
	while(begin<end && key != vec[mid].key){
		if(key > vec[mid].key)
		begin = mid+1;
		else
		end = mid-1;
		
		mid = (begin+end)/2;
	}
	if(key == vec[mid].key)
	return mid;
	
	return -1;
}

main(){
	Obj vec[Maxtam];
	Obj aux;
	int x,key,indice;
	for(x=0; x<Maxtam;x++){
		scanf("%d", &aux.num);
		aux.key = x+1;
		vec[x] = aux;
	}
	printf("enter the key");
	scanf("%d",&key);
	indice = BinSearch(vec,key);
	if(indice>0)
	printf("key - %d  Value %d", vec[indice].key,vec[indice].num);
	
	else
	printf("Not Found");
	
}
