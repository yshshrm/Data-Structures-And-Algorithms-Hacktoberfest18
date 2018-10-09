package adt.linkedList;

public class SingleLinkedListImpl<T> implements LinkedList<T> {

	protected SingleLinkedListNode<T> head;

	public SingleLinkedListImpl() {
		this.head = new SingleLinkedListNode<T>();
	}

	@Override
	public boolean isEmpty() {
		return head.isNIL();
	}

	@Override
	public int size() {
		int size = 0;
		SingleLinkedListNode<T> auxNode = getHead();
		while (!(auxNode.isNIL())) {
			size++;
			auxNode = auxNode.getNext();
		}
		return size;
	}

	@Override
	public T search(T element) {
		T result = null;
		if (element != null) {
			SingleLinkedListNode<T> node = getHead();
			while (!(node.isNIL()) && !(node.getData().equals(element))) {
				node = node.getNext();
			}
			result = node.getData();
		}
		return result;
	}

	@Override
	public void insert(T element) {
		if (element != null) {
			SingleLinkedListNode<T> auxHead = getHead();
			while (!auxHead.isNIL()) {
				auxHead = auxHead.getNext();
			}
			auxHead.setData(element);
			auxHead.setNext(new SingleLinkedListNode<T>());
		}

	}

	@Override
	public void remove(T element) {
		if (element != null) {
			if (!getHead().isNIL()) {
				SingleLinkedListNode<T> auxHead = getHead();
				while (!auxHead.getNext().isNIL() && !auxHead.getNext().getData().equals(element)) {
					auxHead = auxHead.getNext();
				}
				if (!auxHead.getNext().isNIL()) {
					auxHead.setNext(auxHead.getNext().getNext());
				}
			}
		}
	}

	@Override
	public T[] toArray() {
		@SuppressWarnings("unchecked")
		T[] result = (T[]) new Object[this.size()];
		SingleLinkedListNode<T> auxNode = getHead();
		int index = 0;
		while (!(auxNode.isNIL())) {
			result[index] = auxNode.getData();
			auxNode = auxNode.getNext();
			index++;
		}
		return result;
	}

	public SingleLinkedListNode<T> getHead() {
		return head;
	}

	public void setHead(SingleLinkedListNode<T> head) {
		this.head = head;
	}

}
