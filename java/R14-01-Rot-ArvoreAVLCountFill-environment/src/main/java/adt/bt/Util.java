package adt.bt;

import adt.bst.BSTNode;

public class Util {

	/**
	 * A rotacao a esquerda em node deve subir e retornar seu filho a direita
	 * 
	 * @param node
	 * @return
	 */
	public static <T extends Comparable<T>> BSTNode<T> leftRotation(BSTNode<T> node) {
		BSTNode<T> pivot = (BSTNode<T>) node.getRight();
		pivot.setParent(node.getParent());
		if (pivot.getParent() != null) {
			if (node.getParent().getLeft().equals(node)) {
				pivot.getParent().setLeft(pivot);
			} else {
				pivot.getParent().setRight(pivot);
			}
		}
		node.setRight(pivot.getLeft());
		node.getRight().setParent(node);
		node.setParent(pivot);
		pivot.setLeft(node);
		pivot.getLeft().setParent(pivot);
		node = pivot;
		return node;
	}

	/**
	 * A rotacao a direita em node deve subir e retornar seu filho a esquerda
	 * 
	 * @param node
	 * @return
	 */
	public static <T extends Comparable<T>> BSTNode<T> rightRotation(BSTNode<T> node) {
		BSTNode<T> pivot = (BSTNode<T>) node.getLeft();
		pivot.setParent(node.getParent());
		if (pivot.getParent() != null) {
			if (node.getParent().getLeft().equals(node)) {
				pivot.getParent().setLeft(pivot);
			} else {
				pivot.getParent().setRight(pivot);
			}
		}
		node.setLeft(pivot.getRight());
		node.getLeft().setParent(node);
		node.setParent(pivot);
		pivot.setRight(node);
		pivot.getRight().setParent(pivot);
		node = pivot;
		return node;
	}

	public static <T extends Comparable<T>> T[] makeArrayOfComparable(int size) {
		@SuppressWarnings("unchecked")
		T[] array = (T[]) new Comparable[size];
		return array;
	}

}
