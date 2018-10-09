package adt.bst.extended;

import java.util.Comparator;

import adt.bst.BSTImpl;
import adt.bst.BSTNode;

/**
 * Implementacao de SortComparatorBST, uma BST que usa um comparator interno em suas funcionalidades
 * e possui um metodo de ordenar um array dado como parametro, retornando o resultado do percurso
 * desejado que produz o array ordenado. 
 * 
 * @author Adalberto
 *
 * @param <T>
 */
public class SortComparatorBSTImpl<T extends Comparable<T>> extends BSTImpl<T> implements SortComparatorBST<T> {

	private Comparator<T> comparator;
	
	public SortComparatorBSTImpl(Comparator<T> comparator) {
		super();
		this.comparator = comparator;
	}
	
	@Override
	public BSTNode<T> search(T element) {
		return binarySearch(getRoot(), element);
	}

	
	@SuppressWarnings("unchecked")
	private BSTNode<T> binarySearch(BSTNode<T> node, T element) {
		BSTNode<T> result = new BSTNode.Builder<T>().data(null).left(null).right(null).parent(null).build();
		if (node.isEmpty() || getComparator().compare(node.getData(), element) == 0) {
			result = node;
		} else if (getComparator().compare(node.getData(),element) > 0) {
			result = binarySearch((BSTNode<T>) node.getLeft(), element);
		} else {
			result = binarySearch((BSTNode<T>) node.getRight(), element);
		}
		return result;
	}
	
	@Override
	public void insert(T element) {
		insertWithNode(getRoot(), element);
	}

	@SuppressWarnings("unchecked")
	private void insertWithNode(BSTNode<T> node, T element) {
		if (node.isEmpty()) {
			node.setData(element);
			node.setLeft(new BSTNode.Builder<T>().data(null).parent(node).build());
			node.setRight(new BSTNode.Builder<T>().data(null).parent(node).build());
		} else {
			if ((getComparator().compare(element, node.getData()) < 0)) {
				insertWithNode((BSTNode<T>) node.getLeft(), element);
			} else if ((element.compareTo(node.getData()) > 0)) {
				insertWithNode((BSTNode<T>) node.getRight(), element);
			}

		}
		
	}
	
	@Override
	public BSTNode<T> sucessor(T element) {
		BSTNode<T> result = null;
		BSTNode<T> node = search(element);		
		if (!(node.isEmpty())) {
			if (!(node.getRight().isEmpty())) {
				result = minimumWithNode((BSTNode<T>) node.getRight());
			} else {
				result = (BSTNode<T>) node.getParent();
				while (result != null && sameData(node.getData(), result.getRight().getData())) {
					node = result;
					result = (BSTNode<T>) result.getParent();
				}				
			}
		}
		return result;
		
	}
	
	private boolean sameData(T data1, T data2) {
		if (data1 == null || data2 == null) {
			return false;
		}
		return getComparator().compare(data1, data2) == 0;
	}

	@Override
	public BSTNode<T> predecessor(T element) {
		BSTNode<T> result = null;
		BSTNode<T> node = search(element);		
		if (!(node.isEmpty())) {
			if (!(node.getLeft().isEmpty())) {
				result = maximumWithNode((BSTNode<T>) node.getLeft());
			} else {
				result = (BSTNode<T>) node.getParent();
				while (result != null && sameData(node.getData(), result.getLeft().getData())) {
					node = result;
					result = (BSTNode<T>) result.getParent();
				}				
			}
		}
		return result;
	}
	
	@Override
	public void remove(T element) {
		BSTNode<T> node = search(element);
		removeRecursive(node);
	}

	private void removeRecursive(BSTNode<T> node) {
		if (!node.isEmpty()) {
			if (node.isLeaf()) {
				node.setData(null);
				node.setLeft(null);
				node.setRight(null);
			} else if (hasOneChild(node)) {
				if (!(getComparator().compare(node.getData(), getRoot().getData()) == 0 && node.getParent() == null)) {
					if (getComparator().compare(node.getParent().getLeft().getData(), node.getData()) == 0) {
						if (!node.getLeft().isEmpty()) {

							node.getParent().setLeft(node.getLeft());
							node.getLeft().setParent(node.getParent());

						} else {
							node.getParent().setLeft(node.getRight());
							node.getRight().setParent(node.getParent());
						}

					} else {
						if (!node.getLeft().isEmpty()) {

							node.getParent().setRight(node.getLeft());
							node.getLeft().setParent(node.getParent());
						} else {

							node.getParent().setRight(node.getRight());
							node.getRight().setParent(node.getParent());

						}
					}
				} else {
					if (getRoot().getLeft().isEmpty()) {
						setRoot((BSTNode<T>) getRoot().getRight());
						getRoot().setParent(null);
					} else if (getRoot().getRight().isEmpty()) {
						setRoot((BSTNode<T>) getRoot().getLeft());
						getRoot().setParent(null);
					}
				}

			} else {
				BSTNode<T> sucessor = sucessor(node.getData());
				node.setData(sucessor.getData());
				removeRecursive(sucessor);
			}
		}	
	}
	
	@Override
	public T[] sort(T[] array) {
		setRoot(new BSTNode<T>());
		for (int i = 0; i < array.length; i++) {
			insert(array[i]);
		}
		return order();
	}

	@Override
	public T[] reverseOrder() {
		T[] array = util.Util.<T>makeArrayOfComparable(size());
		orderRecursive(getRoot(), array);
		return array;
	}
	
	private void orderRecursive(BSTNode<T> node, T[] array) {
		if (!node.isEmpty()) {
			orderRecursive((BSTNode<T>) node.getRight(), array);
			add(array, node.getData());
			orderRecursive((BSTNode<T>) node.getLeft(), array);
					
		}
		
	}

	public Comparator<T> getComparator() {
		return comparator;
	}

	public void setComparator(Comparator<T> comparator) {
		this.comparator = comparator;
	}
	
}
