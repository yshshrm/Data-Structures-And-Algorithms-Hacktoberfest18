package adt.bst;

public class BSTImpl<T extends Comparable<T>> implements BST<T> {

	protected BSTNode<T> node;

	public BSTImpl() {
		node = new BSTNode<T>();
	}

	public BSTNode<T> getRoot() {
		return this.node;
	}
	
	protected void setRoot(BSTNode<T> node) {
		this.node = node;
	}

	@Override
	public boolean isEmpty() {
		return node.isEmpty();
	}

	@Override
	public int height() {
		return getHeight(getRoot());
	}

	private int getHeight(BSTNode<T> node) {
		int height = -1;
		if (!node.isEmpty()) {
			int heightLeft = getHeight((BSTNode<T>) node.getLeft());
			int heightRight = getHeight((BSTNode<T>) node.getRight());
			height = 1 + longer(heightLeft, heightRight);
		}
		return height;
		
	}

	private int longer(int heightLeft, int heightRight) {
		int result = heightLeft;
		if (heightRight > heightLeft) {
			result = heightRight;
		}
		return result;
	}

	@Override
	public BSTNode<T> search(T element) {
		return binarySearch(getRoot(), element);
	}

	
	@SuppressWarnings("unchecked")
	private BSTNode<T> binarySearch(BSTNode<T> node, T element) {
		BSTNode<T> result = new BSTNode.Builder<T>().data(null).left(null).right(null).parent(null).build();
		if (node.isEmpty() || node.getData().equals(element)) {
			result = node;
		} else if (node.getData().compareTo(element) > 0) {
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
			if ((element.compareTo(node.getData()) < 0)) {
				insertWithNode((BSTNode<T>) node.getLeft(), element);
			} else if ((element.compareTo(node.getData()) > 0)) {
				insertWithNode((BSTNode<T>) node.getRight(), element);
			}

		}
		
	}

	@Override
	public BSTNode<T> maximum() {
		return maximumWithNode(getRoot());
	}

	protected BSTNode<T> maximumWithNode(BSTNode<T> node) {
		BSTNode<T> max = null;
		if (!(node.isEmpty())) {
			max = node;
			while (!(max.getRight().isEmpty())) {
				max = (BSTNode<T>) max.getRight();
			}
		}
		return max;
	}

	@Override
	public BSTNode<T> minimum() {
		return minimumWithNode(getRoot());
	}

	protected BSTNode<T> minimumWithNode(BSTNode<T> node) {
		BSTNode<T> min = null;
		if (!(node.isEmpty())) {
			min = node;
			while (!(min.getLeft().isEmpty())) {
				min = (BSTNode<T>) min.getLeft();
			}
		}		
		return min;
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
				while (result != null && node.equals(result.getRight())) {
					node = result;
					result = (BSTNode<T>) result.getParent();
				}				
			}
		}
		return result;
		
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
				while (result != null && node.equals(result.getLeft())) {
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
				if (!(node.equals(getRoot()) && node.getParent() == null)) {
					if (node.getParent().getLeft().equals(node)) {
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

	protected boolean hasOneChild(BSTNode<T> node) {
		return !(node.getLeft().isEmpty() && node.getRight().isEmpty())	&& (node.getLeft().isEmpty() || node.getRight().isEmpty());
	}

	@Override
	public T[] preOrder() {
		T[] array = util.Util.<T>makeArrayOfComparable(size());
		preOrderRecursive(getRoot(), array);
		return array;
	}

	private void preOrderRecursive(BSTNode<T> node, T[] array) {
		if (!node.isEmpty()) {
			add(array,node.getData());
			preOrderRecursive((BSTNode<T>) node.getLeft(), array);
			preOrderRecursive((BSTNode<T>) node.getRight(), array);
		}		
	}

	protected void add(T[] array, T data) {
		int i = 0;
		while (i < array.length) {
			if (array[i] == null) {
				array[i] = data;
				break;
			} else {
				i++;
			}
		}
	}

	@Override
	public T[] order() {
		T[] array = util.Util.<T>makeArrayOfComparable(size());
		orderRecursive(getRoot(), array);
		return array;
	}

	private void orderRecursive(BSTNode<T> node, T[] array) {
		if (!node.isEmpty()) {
			orderRecursive((BSTNode<T>) node.getLeft(), array);
			add(array, node.getData());
			orderRecursive((BSTNode<T>) node.getRight(), array);
		}
		
	}

	@Override
	public T[] postOrder() {
		T[] array = util.Util.<T>makeArrayOfComparable(size());
		postOrderRecursive(getRoot(), array);
		return array;
	}

	private void postOrderRecursive(BSTNode<T> node, T[] array) {
		if (!node.isEmpty()) {
			postOrderRecursive((BSTNode<T>) node.getLeft(), array);
			postOrderRecursive((BSTNode<T>) node.getRight(), array);
			add(array, node.getData());
		}		
	}

	/**
	 * This method is already implemented using recursion. You must understand
	 * how it work and use similar idea with the other methods.
	 */
	@Override
	public int size() {
		return size(node);
	}

	private int size(BSTNode<T> node) {
		int result = 0;
		// base case means doing nothing (return 0)
		if (!node.isEmpty()) { // indusctive case
			result = 1 + size((BSTNode<T>) node.getLeft()) + size((BSTNode<T>) node.getRight());
		}
		return result;
	}

}
