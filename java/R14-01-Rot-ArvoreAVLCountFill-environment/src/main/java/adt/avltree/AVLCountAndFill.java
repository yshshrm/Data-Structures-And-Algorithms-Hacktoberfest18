package adt.avltree;

public interface AVLCountAndFill<T extends Comparable<T>> extends AVLTree<T> {

	/**
	 * The number of LL cases
	 * 
	 * @return the number of LL cases
	 */
	public int LLcount();

	/**
	 * The number of LR cases
	 * 
	 * @return the number of LR cases
	 */
	public int LRcount();

	/**
	 * The number of RR cases
	 * 
	 * @return the number of RR cases
	 */
	public int RRcount();

	/**
	 * The number of RL cases
	 * 
	 * @return the number of RL cases
	 */
	public int RLcount();

	/**
	 * It fills this AVL tree with the elements from the array argument, while
	 * avoiding any rotation operation. Any existing elements must be kept in
	 * the tree. You must use only the <b><em>insert</em></b> method to add new
	 * elements to the tree.
	 * 
	 * @param array
	 *            the array containing the data to be inserted in this tree.
	 */
	public void fillWithoutRebalance(T[] array);
}
