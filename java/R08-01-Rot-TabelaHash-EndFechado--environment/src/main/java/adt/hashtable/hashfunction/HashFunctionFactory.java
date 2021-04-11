package adt.hashtable.hashfunction;


/**
 * This class is responsible to create hash functions suitable to each kind of
 * hash table.
 * 
 * @author Adalberto
 *
 */
public class HashFunctionFactory<T> {

	public static HashFunction createHashFunction(
			HashFunctionClosedAddressMethod method, int tableSize) {
		HashFunction result = null;
		switch (method) {
		case DIVISION:
			result = new HashFunctionDivisionMethod(tableSize);
			break;
		case MULTIPLICATION:
			result = new HashFunctionMultiplicationMethod(tableSize);
			break;
		}

		return result;
	}

}
