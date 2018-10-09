package adt.hashtable.hashfunction;

public class HashFunctionLinearProbing<T> implements HashFunctionOpenAddress<T> {

	protected HashFunctionClosedAddress<T> originalHashFunction;
	private int tableCapacity;

	public HashFunctionLinearProbing(int tableCapacity,
			HashFunctionClosedAddressMethod method) {
		this.tableCapacity = tableCapacity;
		if (method == HashFunctionClosedAddressMethod.DIVISION) {
			originalHashFunction = new HashFunctionDivisionMethod<T>(
					tableCapacity);
		} else {
			originalHashFunction = new HashFunctionMultiplicationMethod<T>(
					tableCapacity);
		}
	}

	/**
	 * The hash function considering open address with linear probing. It uses
	 * the hashCode method inherited from Object.
	 */
	@Override
	public int hash(T element, int probe) {
		int generatedIndex = 0;

		generatedIndex = ((originalHashFunction.hash(element) + probe) % this.tableCapacity);

		return generatedIndex;
	}
}
