package adt.linkedList;

public class RecursiveDoubleLinkedListImpl<T> extends RecursiveSingleLinkedListImpl<T> implements DoubleLinkedList<T> {

	protected RecursiveDoubleLinkedListImpl<T> previous;

	public RecursiveDoubleLinkedListImpl() {

	}

	public RecursiveDoubleLinkedListImpl(T data, RecursiveSingleLinkedListImpl<T> next,
			RecursiveDoubleLinkedListImpl<T> previous) {
		super(data, next);
		this.previous = previous;
	}

	@Override
	public void insertFirst(T element) {
		if (element != null) {
			if (isEmpty()) {
				insert(element);
			} else {
				setPrevious(new RecursiveDoubleLinkedListImpl<T>(element, this, new RecursiveDoubleLinkedListImpl<T>()));
			}
		}
	}

	@Override
	public void removeFirst() {
		if (!(isEmpty())) {
			if (getNext() != null) {
				setData(getNext().getData());
				((RecursiveDoubleLinkedListImpl<T>) getNext()).removeFirst();
			} else {
				removeLast();
			}
		}
	}

	@Override
	public void removeLast() {
		if (!(isEmpty())) {
			if (getNext().isEmpty()) {
				setData(null);
				setNext(null);
			} else {
				((RecursiveDoubleLinkedListImpl<T>) getNext()).removeLast();
			}
		}
	}

	@Override
	public void insert(T element) {
		if (element != null) {
			if (isEmpty()) {
				setData(element);
				RecursiveDoubleLinkedListImpl<T> nextNIL = new RecursiveDoubleLinkedListImpl<T>();
				setNext(nextNIL);
				nextNIL.setPrevious(this);
				if (getPrevious() == null) {
					RecursiveDoubleLinkedListImpl<T> prevNIL = new RecursiveDoubleLinkedListImpl<T>();
					setPrevious(prevNIL);
					prevNIL.setNext(this);
				}
			} else {
				getNext().insert(element);

			}
		}
	}

	public RecursiveDoubleLinkedListImpl<T> getPrevious() {
		return previous;
	}

	public void setPrevious(RecursiveDoubleLinkedListImpl<T> previous) {
		this.previous = previous;
	}

}
