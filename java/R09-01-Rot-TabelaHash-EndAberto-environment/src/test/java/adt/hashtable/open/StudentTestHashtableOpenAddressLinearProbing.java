package adt.hashtable.open;

import static org.junit.Assert.*;

import org.junit.Before;
import org.junit.Test;

import adt.hashtable.hashfunction.HashFunctionClosedAddressMethod;
import adt.hashtable.open.AbstractHashtableOpenAddress;
import adt.hashtable.open.HashtableElement;
import adt.hashtable.open.HashtableOpenAddressLinearProbingImpl;

public class StudentTestHashtableOpenAddressLinearProbing {

	protected AbstractHashtableOpenAddress<HashtableElement> table1;
	protected AbstractHashtableOpenAddress<HashtableElement> table2;

	protected final int PROPOSED_SIZE = 10;

	@Before
	public void setUp() throws Exception {
		table1 = new HashtableOpenAddressLinearProbingImpl<HashtableElement>(
				PROPOSED_SIZE, HashFunctionClosedAddressMethod.DIVISION);
		// o tamanho real utilizado vai ser PROPOSED_SIZE
		table1.insert(new HashtableElement(2)); // coloca no slot indexado com 2
		table1.insert(new HashtableElement(3)); // coloca no slot indexado com 3
		table1.insert(new HashtableElement(4)); // coloca no slot indexado com 4
		table1.insert(new HashtableElement(5)); // coloca no slot indexado com 5

		table2 = new HashtableOpenAddressLinearProbingImpl<HashtableElement>(
				PROPOSED_SIZE, HashFunctionClosedAddressMethod.DIVISION);
	}

	@Test
	public void testInsert() {
		assertEquals(0, table1.getCOLLISIONS());
		table1.insert(new HashtableElement(7)); // nao produz colisao. coloca no
												// slot indexado com 7
		assertEquals(7, table1.indexOf(new HashtableElement(7)));
		assertEquals(0, table1.getCOLLISIONS());

		table1.insert(new HashtableElement(9)); // nao produz colisao. coloca no
												// slot indexado com 9
		assertEquals(9, table1.indexOf(new HashtableElement(9)));
		assertEquals(0, table1.getCOLLISIONS());

		table1.insert(new HashtableElement(12)); // produz colisao com o 2.
													// coloca no slot indexado
													// com 6 (prox disponivel)
		assertEquals(6, table1.indexOf(new HashtableElement(12)));
		assertEquals(4, table1.getCOLLISIONS());

		table2.insert(new HashtableElement(14)); // nao produz colisao. coloca
													// no slot indexado com 4
		assertEquals(4, table2.indexOf(new HashtableElement(14)));
		assertEquals(0, table2.getCOLLISIONS());

	}

	@Test
	public void testRemove() {
		table1.remove(new HashtableElement(12)); // elemento inexistente
		assertEquals(4, table1.size());

		table1.remove(new HashtableElement(5)); // elemento existente
		assertEquals(3, table1.size());
		assertNull(table1.search(new HashtableElement(5)));

	}

	@Test
	public void testSearch() {
		assertEquals(new HashtableElement(5),
				table1.search(new HashtableElement(5))); // elemento que existe
		assertNull(table1.search(new HashtableElement(15))); // elemento que nao
																// existe
	}

	@Test
	public void testIsEmpty() {
		assertFalse(table1.isEmpty());
		table1.remove(new HashtableElement(2)); // esvazia
		table1.remove(new HashtableElement(3));
		table1.remove(new HashtableElement(4));
		table1.remove(new HashtableElement(5));
		assertTrue(table1.isEmpty());

		assertTrue(table2.isEmpty());
	}

	@Test
	public void testIsFull() {
		assertFalse(table1.isFull());
		table1.insert(new HashtableElement(1)); // enche a tabela
		table1.insert(new HashtableElement(6));
		table1.insert(new HashtableElement(7));
		table1.insert(new HashtableElement(8));
		table1.insert(new HashtableElement(9));
		table1.insert(new HashtableElement(10));
		assertTrue(table1.isFull());

		assertFalse(table2.isFull());
	}

	@Test
	public void testSize() {
		assertEquals(4, table1.size());
	}

}
