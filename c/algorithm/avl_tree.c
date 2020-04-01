// Author: Felipe Pfeifer Rubin
// Contact: felipe.rubin@acad.pucrs.br
#include <stdio.h>
#include <iostream>
#ifndef AVLTree_
#define AVLTree_

template<class T>
struct node{
	int index;
	int height;
	T data;
	node<T> *left;
	node<T> *right;

};

template<class T>
class AVLTree{

public:
	AVLTree();
	

	void insert(int val, T data);
	T search(int val);
	T searchProximity(int val);
private:
	node<T> *insert(node<T> *p, int val, T data);
	T search(int val, node<T> *p);
	T searchProximity(int val, node<T> *p); //No caso de pegar o + proximo do valor
	node<T>*root;
	int getHeight(node<T> *p);
	void updateHeight(node<T> *p);
	int getBalance(node<T> *p);
	node<T> *rotateLeft(node<T> *p);
	node<T> *rotateRight(node<T> *p);

};



template<class T>
AVLTree<T>::AVLTree()
{
	root = (nullptr);
}

template<class T>
T AVLTree<T>::search(int val){
	return search(val,root);
}

template<class T>
T AVLTree<T>::search(int val,node<T> *p){
	if(p == NULL) return T(); //o q retornar entao ?, classe vazia?

	if(p->index == val) return p->data;

	if(p->index < val) return search(val,p->left);

	return search(val,p->right);
}

template<class T>
T AVLTree<T>::searchProximity(int val){
	return searchProximity(val,root);
}

template<class T>
T AVLTree<T>::searchProximity(int val,node<T> *p){
	if(p == NULL) return T(); //o q retornar entao ?, classe vazia?

	if(p->index == val) return p->data;

	if(p->index < val){
		if(p->left == NULL) return p->data;

		return search(val,p->left);
	}else{
		if(p->right == NULL) return p->data;

		return search(val,p->right);
	}

}

template<class T>
void AVLTree<T>::insert(int val, T data){
	root = insert(root,val,data);
}


template<class T>
node<T>* AVLTree<T>::insert(node<T> *p, int val, T data){
	// if(p == NULL) return new node<T>(val,data);
	if(p == NULL){
		p = new node<T>();
		p->height = 1;
		p->index = val;
		p->data = data;
		p->left = NULL;
		p->right = NULL;
		return p;
	}
	if(p->index < val) p->left = insert(p->left,val,data);
	else if(p->index > val) p->right = insert(p->right,val,data);
	else return p;

	updateHeight(p);

	int balance = getBalance(p);

	if(balance > 1){
		if(val < p->left->index){
			p = rotateRight(p);
		}else{
			p->left = rotateLeft(p->left);
			// rotateLeft(p->left);
			p = rotateRight(p);
		}
	}else if(balance < -1){
		if(val > p->right->index){

			p = rotateLeft(p);

		}else{
			// p->right = rotateRight(p->right);
			rotateRight(p->right);
			p = rotateLeft(p);
		}
	}

	return p;
}
template<class T>
node<T>* AVLTree<T>::rotateLeft(node<T> *p){
	if(p == NULL) return NULL;
	node<T> *aux = p->right;

	p->right = aux->left;
	aux->left = p;

	updateHeight(p);
	updateHeight(aux);
	return aux;
}

template<class T>
node<T> *AVLTree<T>::rotateRight(node<T> *p){
	if(p == NULL) return NULL;
	node<T> *aux = p->left;

	p->left = aux->right;
	aux->right = p;

	updateHeight(p);
	updateHeight(aux);
	return aux;	
}

template<class T>
int AVLTree<T>::getBalance(node<T> *p){
	if(p == NULL) return 0;

	return getHeight(p->left) - getHeight(p->right);
}
template<class T>
int AVLTree<T>::getHeight(node<T> *p){
	if(p == NULL) return 0;
	return p->height;
}

template<class T>
void AVLTree<T>::updateHeight(node<T> *p){
	if(p == NULL) return;

	int lheight = getHeight(p->left);
	int rheight = getHeight(p->right);
	if(lheight > rheight){
		p->height = lheight +1;
	}else{
		p->height = rheight + 1;
	}
}
// int main()
// {	
// 	// Exemplo *exemplo = new Exemplo();
// 	// AVLTree<Exemplo> *t = new AVLTree<Exemplo>();

// 	// t->insert(10,*exemplo);
// 	AVLTree<std::string> avlt;
// 	avlt.insert(12,"ax");
// 	avlt.insert(13,"axx");
// 	std::string k = avlt.search(12);
// 	std::string k2 = avlt.search(13);
// 	std::string k3 = avlt.search(23);


// 	printf("%s\n",k.c_str());
// 	printf("%s\n",k2.c_str());
// 	// printf("%s\n",k3.c_str());

// 	return 0;
// }
#endif
