package adt.hashtable.hashfunction;

public class HashFunctionMultiplicationMethod<T> implements
		HashFunctionClosedAddress<T> {

	protected int tableSize;
	private static final double A = (Math.sqrt(5) - 1) / 2;

	public HashFunctionMultiplicationMethod(int tableSize) {
		this.tableSize = tableSize;
	}

	/**
	 * The hash function might use the table size to calculate the hash of any
	 * object of type T. The hash function has as body
	 * <code>h(k) = m (kA % 1)</code>, where <code>k</code> is the key and
	 * <code>m</code> is the table size (stored in the filed
	 * <code>tableSize</code>) and <code>A</code> is the constant defined
	 * <code>(Math.sqrt(5)-1)/2</code> .
	 * 
	 * The key is obtained from hashCode method of type T (inherited from Object
	 * or overridden by you). Thus, if you use a type with hashCode
	 * implementation, no change is necessary. Otherwise, you must implement the
	 * hashCde method of T.
	 */
	@Override
	public int hash(T element) {
		int hashKey = -1;
		int key = element.hashCode();
		double fractionalPart = key * A - Math.floor(key * A);
		hashKey = (int) (tableSize * fractionalPart);

		return hashKey;
	}
}
