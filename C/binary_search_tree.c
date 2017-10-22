#include <stdio.h>
#include <stdlib.h>
typedef struct No* arvbin;
typedef struct Info{
	int valor;
}Info;

struct No{
 struct No *dir;
 struct No *esq;
 Info info;
 };
 
arvbin* cria();
int Push(Info info, arvbin* raiz);

arvbin* cria(){
	arvbin* novo;
	novo = (arvbin*) malloc(sizeof(arvbin));
	if(novo!=NULL){
	*novo = NULL;
	return novo;
	} 
	else return NULL;
}

int Push(Info info, arvbin* raiz){
	arvbin novo = (arvbin) malloc(sizeof(struct No));
	novo->info = info;
	novo->dir = NULL;
	novo->esq = NULL;
	if(*raiz == NULL){
		*raiz = novo;
	//	printf("1 elemento add\n");
		return 1;
	}
	else{
		arvbin ant = NULL;
		arvbin atual = *raiz;
		while(atual!=NULL){
			ant=atual;
			if(info.valor == atual->info.valor){
			//	printf("Valor repetido");
				free(novo);
				return 0;
			}
			else if(info.valor > atual->info.valor){
			//	ant = atual;
				atual = atual->dir;
			}
			
			else{
			//	ant=atual;
				atual = atual->esq;
			}
			
			}
			//	printf("saiu do loop\n");
			if(info.valor >ant->info.valor)
			ant->dir = novo;
			
			else
			ant->esq = novo;
		
	}
	return 1;
}

void DestroiNo(arvbin no){
	if(no == NULL) return;
	DestroiNo(no->dir);
	DestroiNo(no->esq);
	free(no);
	no = NULL;
}

void DestroiArv(arvbin* raiz){
	if(raiz == NULL) return;
	DestroiNo(*raiz);
	free(raiz);
	raiz = NULL;
}


void ImprimirNo(arvbin no){
	if(no==NULL){
	//printf("\n");
	return;
	} 
		
	printf(" %d \n", no->info.valor);
	//printf("dir\n");
	ImprimirNo(no->dir);
//	printf("esq\n");
	ImprimirNo(no->esq);
}

void ImprimirArv(arvbin* raiz){
	if(raiz == NULL){
		printf("\n");
		return;
	}
	ImprimirNo(*raiz);
}

int ArvVazia(arvbin* arv){
	return(*arv == NULL);
}

int NumNo(arvbin no){
	if(no != NULL)
	return 1 + NumNo(no->esq) + NumNo(no->dir);
	if(no==NULL)
	return 0;
//	NumNo(no->esq);
//	NumNo(no->dir);
}



int altura(arvbin* raiz){
	if(raiz == NULL){
		return 0;
	}
	if(*raiz == NULL)
	return 0;
	
	int alt_esq = altura(&((*raiz)->esq));
	int alt_dir = altura(&((*raiz)->dir));
	if(alt_esq >= alt_dir){
		return 1 + alt_esq;
	}
	else
	return 1+alt_dir;
}


arvbin BuscaLinear(arvbin* raiz,Info info){
	if(raiz == NULL || *raiz == NULL)
		return NULL;
	
	arvbin No = *raiz;
	while(No!=NULL){
		if(No->info.valor == info.valor)
		break;
		
		if(info.valor > No->info.valor)
		No = No->dir;
		else
		No = No->esq;
	}
	return No;
}

arvbin BuscaRecursiva(arvbin* raiz,Info info){
	if((*raiz)->info.valor == info.valor ){
		return *raiz;
	}
	if(info.valor > (*raiz)->info.valor )
	return BuscaRecursiva( &((*raiz)->dir), info);
	else
	return BuscaRecursiva( &((*raiz)->esq), info);
	
}


