package adt.bst.extended;

import adt.bst.BST;

/**
 * Interface definindo uma BST que trabalha obrigatoriamente com um comparator. 
 * Dessa forma, toda e qualquer comparacao feita pela implementacao deve usar 
 * o comparator.
 * @author Adalberto
 *
 */
public interface SortComparatorBST<T extends Comparable<T>> extends BST<T>{

	/**
	 * Metodo que recebe um array de itens e retorna o array ordenado segundo o comparator da BST.
	 * @param array
	 * @return
	 */
	public T[] sort(T[] array);
	
	/**
	 * Novo metodo de percurso na BST que percorre a arvore de forma contraria ao percurso
	 * em ordem. Dessa forma a arvore eh percorrida: DIR, RAIZ, ESQ.
	 * Obs: voce nao pode usar nenhum metodo de percurso implementado. Voce precisa implementar
	 * essa nova forma de percurso.
	 * 
	 * @return
	 */
	public T[] reverseOrder();
}
