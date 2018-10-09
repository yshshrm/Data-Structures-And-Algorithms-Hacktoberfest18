package adt.linkedList;

public class RecursiveSingleLinkedListImpl<T> implements LinkedList<T> {

	protected T data;
	protected RecursiveSingleLinkedListImpl<T> next;

	public RecursiveSingleLinkedListImpl() {

	}

	public RecursiveSingleLinkedListImpl(T data, RecursiveSingleLinkedListImpl<T> next) {
		this.data = data;
		this.next = next;
	}

	@Override
	public boolean isEmpty() {
		boolean result = false;
		if (getData() == null) {
			result = true;
		}
		return result;
	}

	@Override
	public int size() {
		int result = 0;
		if (!(isEmpty())) {
			result = 1 + getNext().size();
		}
		return result;
	}

	@Override
	public T search(T element) {
		T result = null;
		if (element != null) {
			if (!(isEmpty())) {
				if (getData().equals(element)) {
					result = data;
				} else {
					result = getNext().search(element);
				}
			}
		}
		return result;
	}

	@Override
	public void insert(T element) {
		if (element != null) {
			if (isEmpty()) {
				setData(element);
				setNext(new RecursiveSingleLinkedListImpl<T>());
			} else {
				getNext().insert(element);
			}
		}
	}

	@Override
	public void remove(T element) {
		if (element != null) {
			if (!(isEmpty())) {
				if (getData().equals(element)) {
					setData(getNext().getData());
					setNext(getNext().getNext());
				} else {
					getNext().remove(element);
				}
			}
		}

	}

	@Override
	public T[] toArray() {
		@SuppressWarnings("unchecked")
		T[] array = (T[]) new Object[this.size()];
		addArray(array, this, 0);
		return array;
	}

	private void addArray(T[] array, RecursiveSingleLinkedListImpl<T> node, int i) {
		if (!(node.isEmpty())) {
			array[i] = node.getData();
			addArray(array, node.getNext(), ++i);
		}

	}

	public T getData() {
		return data;
	}

	public void setData(T data) {
		this.data = data;
	}

	public RecursiveSingleLinkedListImpl<T> getNext() {
		return next;
	}

	public void setNext(RecursiveSingleLinkedListImpl<T> next) {
		this.next = next;
	}

}
