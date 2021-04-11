package adt.hashtable.hashfunction;

/**
 * It represents a hash function to be used in hashtable that work with closed
 * address.
 */
public interface HashFunctionClosedAddress<T> extends HashFunction<T> {

	/**
	 * The hash function considering closed address.
	 */
	public int hash(T element);
}
