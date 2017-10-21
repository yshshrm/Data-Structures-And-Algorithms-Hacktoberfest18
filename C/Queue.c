#include <stdio.h>
#include <stdlib.h>


typedef struct node* pointer; 

typedef struct Item{
	int key;
}Item;

typedef struct node{
	pointer next;
	Item item;
}node;

typedef struct Queue{
	pointer end;
}Queue;
//Starts the Queue
void StartQueue(Queue* queue){
	queue->end = NULL;	
}
//Add a element on the Queue Back
int Add(Queue* queue, Item item){
	if(queue == NULL)
	return 0;
	
	if(queue->end == NULL){
		queue->end = (pointer) malloc(sizeof(node));
		queue->end->item = item;
		queue->end->next = NULL;
		return 1;
	}
	else{
	pointer aux = (pointer) malloc(sizeof(node));
	aux->item=item;
	aux->next = queue->end;
	queue->end = aux;
	return 1;
	}
	
}
//Remove the Queue front
int Remove(Queue* queue){
	if(queue == NULL)
	return 0;
	pointer front=queue->end;
	pointer that = NULL;
	while(front->next!=NULL){
		that = front;
		front = front->next;
	}
	free(front);
	if(that!=NULL)
	that->next = NULL;
	return 1;
}

//Shows the Queue
void PrintQueue(Queue* queue){
	if (queue == NULL){
		printf("empty\n");
	}
	pointer aux = queue->end ;
	while(aux!=NULL){
		printf("%d \n", aux->item.key);
		aux = aux->next;
	}
}

