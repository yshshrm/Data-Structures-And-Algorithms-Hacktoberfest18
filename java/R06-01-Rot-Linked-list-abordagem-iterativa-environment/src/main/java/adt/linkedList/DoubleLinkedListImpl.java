package adt.linkedList;

public class DoubleLinkedListImpl<T> extends SingleLinkedListImpl<T> implements DoubleLinkedList<T> {

	protected DoubleLinkedListNode<T> last;
	private DoubleLinkedListNode<T> nil;

	public DoubleLinkedListImpl() {
		last = new DoubleLinkedListNode<>();
		head = last;
	}

	@Override
	public void insertFirst(T element) {
		if (element != null) {
			nil = new DoubleLinkedListNode<T>();
			DoubleLinkedListNode<T> newHead = new DoubleLinkedListNode<T>(element, (DoubleLinkedListNode<T>) getHead(),
					nil);
			((DoubleLinkedListNode<T>) getHead()).setPrevious(newHead);
			if (newHead.isNIL()) {
				setLast(newHead);
			}
			setHead(newHead);
		}
	}

	@Override
	public void removeFirst() {
		if (!(getHead().isNIL())) {
			setHead(getHead().getNext());
			if (getHead().isNIL()) {
				setLast((DoubleLinkedListNode<T>) (getHead()));
			}
			if (getHead() instanceof DoubleLinkedListNode) {
				DoubleLinkedListNode<T> head = (DoubleLinkedListNode<T>) getHead();
				nil = new DoubleLinkedListNode<T>();
				head.setPrevious(nil);
			}
		}
	}

	@Override
	public void removeLast() {
		if (!(getLast().isNIL())) {
			setLast(getLast().getPrevious());
			if (getLast().isNIL()) {
				setHead(getLast());
			}
			nil = new DoubleLinkedListNode<T>();
			getLast().setNext(nil);
		}
	}

	@Override
	public void insert(T element) {
		if (element != null) {
			nil = new DoubleLinkedListNode<T>();
			DoubleLinkedListNode<T> newLast = new DoubleLinkedListNode<T>(element, nil, getLast());
			getLast().setNext(newLast);
			if (getLast().isNIL()) {
				setHead(newLast);
			}
			setLast(newLast);
		}

	}

	public DoubleLinkedListNode<T> getLast() {
		return last;
	}

	public void setLast(DoubleLinkedListNode<T> last) {
		this.last = last;
	}

}
