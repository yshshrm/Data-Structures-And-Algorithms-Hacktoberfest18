package adt.hashtable.closed;

import java.util.LinkedList;

import util.Util;
import adt.hashtable.AbstractHashtable;

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
public abstract class AbstractHashtableClosedAddress<T> extends
		AbstractHashtable<T> {

	public AbstractHashtableClosedAddress() {
		super();
	}

	@Override
	protected void initiateInternalTable(int size) {
		this.table = Util.<LinkedList<T>> makeArray(size);
	}
}
