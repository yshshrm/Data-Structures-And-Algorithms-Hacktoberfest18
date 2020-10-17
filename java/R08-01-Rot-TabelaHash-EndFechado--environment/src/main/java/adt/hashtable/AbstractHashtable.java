package adt.hashtable;

import util.Util;
import adt.hashtable.hashfunction.HashFunction;

/**
 * It represents an abstract implementation of a hashtable, with some internal
 * attributes. Note that the kind of the internal array is a parameter because
 * hashtable with closed address should have a collection of elements (chaining)
 * instead of a single element. Moreover, a hashtable working with open address
 * must also manipulate deletions through a special element called DELETED.
 * Thus, it must work with Object instead of a generic type T. An
 * AbstractHashtable is only a resource for unifying both kinds of hashtables
 * (closed and open addressing). Thee real hashtables must inherit this class.
 */
public abstract class AbstractHashtable<T> implements Hashtable<T> {

	protected Object[] table; // the internal table
	protected int elements; // the number of elements inserted into the hash
							// table
	protected int COLLISIONS; // the number of collisions occurred in this
								// hashtable
	protected HashFunction<T> hashFunction; // the hash function used by this
											// hashtable.

	public AbstractHashtable() {
		elements = 0;
		COLLISIONS = 0;
	}

	protected void initiateInternalTable(int size) {
		this.table = Util.<T> makeArray(size);
	}

	@Override
	public boolean isEmpty() {
		return (elements == 0);
	}

	@Override
	public boolean isFull() {
		return (elements == table.length);
	}

	@Override
	public int size() {
		return elements;
	}

	@Override
	public int capacity() {
		return this.table.length;
	}

	public int getCOLLISIONS() {
		return COLLISIONS;
	}

	public HashFunction<T> getHashFunction() {
		return hashFunction;
	}

	public void setHashFunction(HashFunction<T> hashFunction) {
		this.hashFunction = hashFunction;
	}

}
