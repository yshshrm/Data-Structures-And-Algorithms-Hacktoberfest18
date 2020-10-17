package adt.hashtable.hashfunction;

/**
 * It represents a hash function to be used in hashtable that work with open
 * address.
 */
public interface HashFunctionOpenAddress<T> extends HashFunction<T> {
	/**
	 * The hash function considering open address. It uses the hashCode method
	 * inherited from Object.
	 */
	public int hash(T element, int probe);
}
