#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define TAMIN 0 //primeiro elemento da lista
#define TAMAX 100 //numero de elementos na minha lista
typedef int Apontador;
//object on list
	typedef struct{
		int valor;
		int codigo;
	}tipo_objeto;

//list
	typedef struct{
		tipo_objeto objeto[TAMAX];
		Apontador primeiro, ultimo;//aponta para a origem e para o primeiro elemento vazio, respectivamente;
	}tipo_lista;

// starts list;
	void inicia_lista(tipo_lista *plista){
		plista->primeiro = TAMIN;
		plista->ultimo = TAMIN;
	}

//test if list is empty
	int teste_vazio(tipo_lista *plista){
		return (plista->primeiro == plista->ultimo);
		//Retorna um inteiro para o teste acima, 1 caso a lista esteja vaiza, 0 if not;
	}
	
	//test if list is full
	int teste_cheio(tipo_lista *plista){
		return (plista->ultimo == TAMAX);
		//Retorna um inteiro para o teste acima, 1 caso a lista esteja cheia, 0 if not;
	}

//Add element on list
	int add(tipo_lista *plista, tipo_objeto obj){
		//testa se lista esta cheia
		if(teste_cheio(plista)==1){
			return 0;
		}
		plista->objeto[plista->ultimo++] = obj;//adiciona um elemento e avança apontador para frente
		return 1;
	}
	
	//remove element by indice x
	int remove_position(tipo_lista *plista,Apontador x){
		int i;
		//testa se lista vazia
		if(teste_vazio(plista) == 1){
			return 0;
		}
		//test if the element exist
		else if(x>=plista->ultimo){
			return 0;
			
		}
		//move para tras tds os elementos, sobreescrevendo o valor x
		for(i=x; i<plista->ultimo; i++){
			plista->objeto[i] = plista->objeto[i+1];	
		}
		plista->ultimo--;
		plista->objeto[plista->ultimo].codigo = 0;//put 0 as, the last object
		plista->objeto[plista->ultimo].valor = 0;	
		return 1;
	}
	
	//show all elements of the list
	void PrintList(tipo_lista *plista){
		int i;
		for(i=0;i<plista->ultimo;i++){
			printf("Codigo - %d -- Valor - %d\n", plista->objeto[i].codigo,plista->objeto[i].valor);
		}
	}

//remove element by key
int remove_key(tipo_lista *plista, int key){
		int i;
		if(teste_vazio(plista) == 1){
			return 0;
		}
	for(i=0;i<plista->ultimo;i++){
		if(plista->objeto[i].codigo == key){
			remove_position(plista, i);
			return 1;
		}
	}
	//caso nao encontre elemento
	return 0;
}

//Remove all elements with the valor
int remove_valor(tipo_lista *plista, int num){
		int i;
		if(teste_vazio(plista) == 1){
			return 0;
		}
	for(i=0;i<plista->ultimo;i++){
		if(plista->objeto[i].valor == num){
			remove_position(plista, i);
			i--;
			}
	}
	return 0;
}




