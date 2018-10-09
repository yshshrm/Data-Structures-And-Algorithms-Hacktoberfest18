package adt.queue;

import java.util.Comparator;

import adt.heap.HeapImpl;
import adt.heap.HeapNode;

public class QueueHeapImpl<T extends Comparable<T>> implements Queue<T> {

	private int maxElements;
	private int count;
	private HeapImpl heap;
	private long ID;

	public QueueHeapImpl(int numberElements) {
		Comparator<HeapNode<T>> comparator = (o1, o2) -> o2.compareTo(o1);
		heap = new HeapImpl(comparator);
		this.maxElements = numberElements;
		count = 0;
		ID = 0;
	}

	@Override
	public boolean isEmpty() {
		return count == 0;
	}

	@Override
	public boolean isFull() {
		return count == maxElements;
	}

	@Override
	public void enqueue(T element) throws QueueOverflowException {
		if (element != null) {
			if (isFull()) {
				throw new QueueOverflowException();
			}
			HeapNode node = new HeapNode<T>(element, ID);
			count++;
			ID++;
			heap.insert(node);
		}

	}

	@Override
	public T dequeue() throws QueueUnderflowException {
		if (isEmpty()) {
			throw new QueueUnderflowException();
		}
		count--;
		return ((HeapNode<T>) heap.extractRootElement()).getData();
	}

	@Override
	public T head() {
		return ((HeapNode<T>) heap.rootElement()).getData();
	}

}
