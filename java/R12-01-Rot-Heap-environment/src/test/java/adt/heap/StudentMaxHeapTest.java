package adt.heap;

import static org.junit.Assert.assertArrayEquals;
import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertFalse;
import static org.junit.Assert.assertTrue;

import java.util.Arrays;
import java.util.Comparator;

import org.junit.Before;
import org.junit.Test;

public class StudentMaxHeapTest {
	/*
	 * Heap<Integer> heap;
	 * 
	 * @Before public void setUp() { // TODO Instancie seu comparator para fazer
	 * sua estrutura funcionar como // uma max heap aqui. Use instanciacao
	 * anonima da interface // Comparator!!!! //Comparator<Integer> comparator =
	 * null; heap = new HeapImpl<Integer>((o1, o2) -> o1 - o2); }
	 * 
	 * @Test public void testBuild() { heap.buildHeap(new Integer[] { 82, 6, 99,
	 * 12, 34, 64, 58, 1 });
	 * 
	 * assertEquals(8, heap.size()); assertFalse(heap.isEmpty());
	 * 
	 * verifyHeap(new Integer[] { 99, 12, 82, 6, 34, 64, 58, 1 }); }
	 * 
	 * @Test public void testInsert() { heap.insert(8); heap.insert(12);
	 * heap.insert(-2); heap.insert(7); heap.insert(8); heap.insert(-5);
	 * heap.insert(14); heap.insert(3); heap.insert(-10); heap.insert(0);
	 * 
	 * assertEquals(10, heap.size()); assertFalse(heap.isEmpty());
	 * 
	 * verifyHeap(new Integer[] { 14, 8, 12, 7, 8, -5, -2, 3, -10, 0 }); }
	 * 
	 * @Test public void testRemove() { heap.insert(22); heap.insert(45);
	 * heap.insert(38); heap.insert(17); heap.insert(40); heap.insert(15);
	 * heap.insert(26); heap.insert(79); heap.insert(53); heap.insert(30);
	 * 
	 * assertEquals(new Integer(79), heap.extractRootElement());
	 * assertEquals(new Integer(53), heap.extractRootElement());
	 * assertEquals(new Integer(45), heap.extractRootElement());
	 * assertEquals(new Integer(40), heap.extractRootElement());
	 * assertEquals(new Integer(38), heap.extractRootElement());
	 * 
	 * assertEquals(5, heap.size()); assertFalse(heap.isEmpty());
	 * 
	 * verifyHeap(new Integer[] { 22, 17, 15, 26, 30 }); }
	 * 
	 * @Test public void testSort() { assertArrayEquals(new Integer[] { },
	 * heap.heapsort(new Integer[] { }));
	 * 
	 * assertEquals(0, heap.size()); assertTrue(heap.isEmpty());
	 * 
	 * assertArrayEquals(new Integer[] {}, heap.toArray()); }
	 * 
	 * private void verifyHeap(Integer[] expected) { boolean isHeap = true;
	 * 
	 * Comparable<Integer>[] original = heap.toArray();
	 * 
	 * Arrays.sort(expected); Arrays.sort(original);
	 * 
	 * if (Arrays.equals(expected, original) == false) isHeap = false;
	 * 
	 * original = heap.toArray();
	 * 
	 * for (int i = 0; i < original.length; i++) { if (2 * i + 1 <
	 * original.length && original[i].compareTo((Integer) original[2 * i + 1]) <
	 * 0) isHeap = false; if (2 * i + 2 < original.length &&
	 * original[i].compareTo((Integer) original[2 * i + 2]) < 0) isHeap = false;
	 * }
	 * 
	 * assertTrue(isHeap); }
	 */

	HeapImpl<Integer> heap;

	@Before
	public void setUp() {
		// TODO Instancie seu comparator para fazer sua estrutura funcionar como
		// uma max heap aqui. Use instanciacao anonima da interface
		// Comparator!!!!
		Comparator<Integer> comparator = (a, b) -> a.compareTo(b);
		heap = new HeapImpl<Integer>(comparator);
	}

	@Test
	public void testBuild() {
		heap.buildHeap(new Integer[] { 82, 6, 99, 12, 34, 64, 58, 1 });

		assertEquals(8, heap.size());
		assertFalse(heap.isEmpty());

		verifyHeap(new Integer[] { 99, 12, 82, 6, 34, 64, 58, 1 });
	}

	@Test
	public void testInsert() {
		heap.insert(8);
		heap.insert(12);
		heap.insert(-2);
		heap.insert(7);
		heap.insert(8);
		heap.insert(-5);
		heap.insert(14);
		heap.insert(3);
		heap.insert(-10);
		heap.insert(0);

		assertEquals(10, heap.size());
		assertFalse(heap.isEmpty());

		verifyHeap(new Integer[] { 14, 8, 12, 7, 8, -5, -2, 3, -10, 0 });
	}

	@Test
	public void testCustom() {
		assertTrue(heap.isEmpty());
		assertEquals(0, heap.size());

		heap.insert(0);
		heap.insert(10);
		heap.insert(20);
		heap.insert(-1);
		heap.insert(-2);
		heap.insert(Integer.MAX_VALUE);
		heap.insert(Integer.MIN_VALUE);
		heap.insert(1);
		heap.insert(0);
		heap.insert(0);
		heap.insert(12);
		heap.insert(100);
		heap.insert(109);
		heap.insert(101);

		assertFalse(heap.isEmpty());
		assertEquals(14, heap.size());
		verifyHeap(
				new Integer[] { Integer.MAX_VALUE, 12, 109, 0, 1, 100, 101, -1, 0, -2, 0, 10, 20, Integer.MIN_VALUE });

		Integer[] array = new Integer[] { Integer.MAX_VALUE, 12, 109, 0, 1, 100, 101, -1, 0, -2, 0, 10, 20,
				Integer.MIN_VALUE };
		Arrays.sort(array);

		assertArrayEquals(array, heap.heapsort(
				new Integer[] { Integer.MAX_VALUE, 12, 109, 0, 1, 100, 101, -1, 0, -2, 0, 10, 20, Integer.MIN_VALUE }));
		assertTrue(heap.isEmpty());
		verifyHeap(new Integer[] {});

		assertArrayEquals(new Integer[] { 1, 2, 3, 4 }, heap.heapsort(new Integer[] { 4, 2, 3, 1 }));
		assertTrue(heap.isEmpty());
		verifyHeap(new Integer[] {});

		heap.insert(0);
		heap.insert(10);
		heap.insert(20);
		heap.insert(-1);
		heap.insert(-2);
		heap.insert(Integer.MAX_VALUE);
		heap.insert(Integer.MIN_VALUE);
		heap.insert(1);
		heap.insert(0);
		heap.insert(0);
		heap.insert(12);
		heap.insert(100);
		heap.insert(109);
		heap.insert(101);
		heap.insert(null);
		assertEquals(14, heap.size());

		Comparator<Integer> comparator = (a, b) -> a.compareTo(b);
		((HeapImpl) heap).setComparator(comparator);

		assertFalse(heap.isEmpty());
		assertEquals(14, heap.size());
		verifyHeap(
				new Integer[] { Integer.MIN_VALUE, -1, -2, 0, 0, 100, 20, 10, 1, 0, 12, Integer.MAX_VALUE, 109, 101 });
	}

	@Test
	public void testRemove() {
		heap.insert(22);
		heap.insert(45);
		heap.insert(38);
		heap.insert(17);
		heap.insert(40);
		heap.insert(15);
		heap.insert(26);
		heap.insert(79);
		heap.insert(53);
		heap.insert(30);

		assertEquals(new Integer(79), heap.extractRootElement());
		assertEquals(new Integer(53), heap.extractRootElement());
		assertEquals(new Integer(45), heap.extractRootElement());
		assertEquals(new Integer(40), heap.extractRootElement());
		assertEquals(new Integer(38), heap.extractRootElement());

		assertEquals(5, heap.size());
		assertFalse(heap.isEmpty());

		verifyHeap(new Integer[] { 22, 17, 15, 26, 30 });
	}

	@Test
	public void testSort() {
		assertArrayEquals(new Integer[] { 5, 6, 12, 20, 34, 43, 49, 92 },
				heap.heapsort(new Integer[] { 34, 92, 5, 12, 49, 20, 43, 6 }));

		assertEquals(0, heap.size());
		assertTrue(heap.isEmpty());

		assertArrayEquals(new Integer[] {}, heap.toArray());
	}

	private void verifyHeap(Integer[] expected) {
		boolean isHeap = true;

		Comparable<Integer>[] original = heap.toArray();

		Arrays.sort(expected);
		Arrays.sort(original);

		if (Arrays.equals(expected, original) == false)
			isHeap = false;

		original = heap.toArray();

		for (int i = 0; i < original.length; i++) {
			if (2 * i + 1 < original.length && original[i].compareTo((Integer) original[2 * i + 1]) < 0)
				isHeap = false;
			if (2 * i + 2 < original.length && original[i].compareTo((Integer) original[2 * i + 2]) < 0)
				isHeap = false;
		}

		assertTrue(isHeap);
	}

	@Test
	public void testHeapsortMax() {

		assertArrayEquals(new Integer[] { -10, -5, -2, 0, 3, 7, 8, 8, 12, 14 },
				heap.heapSortMax(new Integer[] { 14, 8, 12, 7, 8, -5, -2, 3, -10, 0 }));
	}

}
