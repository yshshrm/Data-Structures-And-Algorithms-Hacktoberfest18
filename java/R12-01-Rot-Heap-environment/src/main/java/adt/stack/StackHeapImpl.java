package adt.stack;

import java.util.Comparator;

import adt.heap.HeapImpl;
import adt.heap.HeapNode;

public class StackHeapImpl<T extends Comparable<T>> implements Stack<T> {

	private int maxElements;
	private int count;
	private HeapImpl heap;
	private long ID;

	public StackHeapImpl(int numberElements) {
		Comparator<HeapNode<T>> comparator = (o1, o2) -> o1.compareTo(o2);
		heap = new HeapImpl(comparator);
		if (numberElements < 0) {
			this.maxElements = 0;
		} else {
			this.maxElements = numberElements;
		}		
		count = 0;
		ID = 0;
	}

	@Override
	public void push(T element) throws StackOverflowException {
		if (element != null) {
			if (isFull()) {
				throw new StackOverflowException();
			}
			HeapNode node = new HeapNode<T>(element, ID);
			count++;
			ID++;
			heap.insert(node);
		}

	}

	@Override
	public T pop() throws StackUnderflowException {
		if (isEmpty()) {
			throw new StackUnderflowException();
		}
		count--;
		return ((HeapNode<T>) heap.extractRootElement()).getData();
	}

	@Override
	public T top() {
		return ((HeapNode<T>) heap.rootElement()).getData();
	}

	@Override
	public boolean isEmpty() {
		return count == 0;
	}

	@Override
	public boolean isFull() {
		return count == maxElements;
	}

}
