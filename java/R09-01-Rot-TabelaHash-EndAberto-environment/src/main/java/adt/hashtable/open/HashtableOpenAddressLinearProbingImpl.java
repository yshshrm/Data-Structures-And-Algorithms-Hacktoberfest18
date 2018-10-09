package adt.hashtable.open;

import adt.hashtable.hashfunction.HashFunctionClosedAddressMethod;
import adt.hashtable.hashfunction.HashFunctionLinearProbing;

public class HashtableOpenAddressLinearProbingImpl<T extends Storable> extends AbstractHashtableOpenAddress<T> {

	public HashtableOpenAddressLinearProbingImpl(int size, HashFunctionClosedAddressMethod method) {
		super(size);
		hashFunction = new HashFunctionLinearProbing<T>(size, method);
		this.initiateInternalTable(size);
	}

	@Override
	public void insert(T element) {
		if (element != null) {
			if (isFull()) {
				throw new HashtableOverflowException();
			} else {
				int i = 0;
				while (i != this.capacity()) {
					int j = hashing(element, i);
					if (this.table[j] == null || this.table[j] instanceof DELETED) {
						this.table[j] = element;
						this.elements++;
						break;
					} else {
						i++;
						this.COLLISIONS++;
					}
				}
			}
		}
	}

	private int hashing(T element, int i) {
		int result = ((HashFunctionLinearProbing<T>) this.getHashFunction()).hash(element, i);
		return result;
	}

	@Override
	public void remove(T element) {
		if (element != null) {
			int i = indexOf(element); 
			if (i != -1) {
				this.table[i] = new DELETED();
				this.elements--;
			}			
		}
	}

	@Override
	public T search(T element) {
		T result = null;
		if (element != null) {
			int i = 0;			
			while (i != this.capacity()) {
				int j = hashing(element, i);
				if (this.table[j] == null) {
					break;
				} else {
					if (this.table[j].equals(element)) {
						result = element;
						break;
					} else {
						i++;
					}

				}
			}			
		}
		return result;		
	}

	@Override
	public int indexOf(T element) {
		int result = -1;
		if (element != null) {
			int i = 0;
			while (i != this.capacity()) {
				int j = hashing(element, i);
				if (this.table[j] == null) {
					break;
				} else {
					if (this.table[j].equals(element)) {
						result = j;
						break;
					} else {
						i++;
					}						
				}
			}
		
		}
		return result;
	}

}
