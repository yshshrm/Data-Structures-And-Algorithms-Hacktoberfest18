package adt.hashtable.open;

public class HashtableOverflowException extends RuntimeException {

	public HashtableOverflowException() {
		super("Hashtable overflow!");
	}

}
