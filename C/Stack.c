#include <stdio.h>
#include <stdlib.h>

typedef struct tipo_info{
	int numero;
}tipo_info;

typedef struct item{
	tipo_info info;
	struct item *proximo;
}tipo_item;
//Pilha Means Stack, in portugues '-'
typedef struct pilha{
	tipo_item *topo;
}tipo_pilha;
//creat the Stack
void cria_pilha(tipo_pilha *pilha){
	pilha->topo = NULL;
}
//test if the stack is empty
short pilha_vazia(tipo_pilha *pilha){
	return (pilha->topo == NULL);
}
//aux to push
tipo_item* pilha_alloc(tipo_info info){
	tipo_item *novo = (tipo_item*) malloc(sizeof(tipo_item));
	novo->proximo = NULL;
	novo->info = info;
	return novo;
}
//add a element at the top
void push(tipo_pilha *pilha, tipo_info info){
	tipo_item *novo, *aux;

	novo = pilha_alloc(info);
	
	if(pilha->topo == NULL){
		pilha->topo = novo;
		return;
	}
	aux = pilha->topo;
	pilha->topo = novo;
	pilha->topo->proximo = aux;	
	
}
//Remove the top element
tipo_info pop(tipo_pilha *pilha){
	tipo_item *aux;

	if(pilha_vazia(pilha)){
		aux->info.numero = -1;
		return aux->info;
	}

	aux = pilha->topo;
	pilha->topo = pilha->topo->proximo;
	tipo_info info = aux->info;
	free(aux);
	return info;
}
//Show the stack
void print_Stack(tipo_pilha *pilha){
	tipo_item *aux;
	
	aux = pilha->topo;
	
	while(aux != NULL){
		printf("%d\n",aux->info.numero);
		aux= aux->proximo;
	}
}

