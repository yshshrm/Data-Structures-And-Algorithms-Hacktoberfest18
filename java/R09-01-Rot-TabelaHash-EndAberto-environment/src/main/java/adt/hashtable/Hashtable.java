package adt.hashtable;

/**
 * The interface of a generic hash table. It keeps values of type T. The table
 * can work in two modes: closed address (with chaining) and open address
 * (linear probing, quadratic probe, double hashing).
 */
public interface Hashtable<T> {

	/**
	 * Determines whether this hashtable is empty or not.
	 */
	public boolean isEmpty();

	/**
	 * Determines whether this hashtable is empty or not. Note that this method
	 * may not make sense in hashtable with closed address, as it works with
	 * linked lists (or buckets) in each position.
	 */
	public boolean isFull();

	/**
	 * It returns the length of the internal table of this hash table.
	 */
	public int capacity();

	/**
	 * Returns how many values have been inserted into the hash table.
	 */
	public int size();

	/**
	 * Inserts a non-null object into the hash table. The hashtable does not
	 * work with duplicated elements. Every time that the insert is called, if
	 * there is a collision, then the attribute COLLISION of this hashtable is
	 * incremented.
	 */
	public void insert(T element);

	/**
	 * Removes an element from the hash table.
	 */
	public void remove(T element);

	/**
	 * Searches a given element in the hash table. If it is not in the table,
	 * the hash table returns null.
	 */
	public T search(T element);

	/**
	 * Searches the index of an element in the hashtable. It returns -1 if the
	 * element is not in the hashtable.
	 */
	public int indexOf(T element);

}
