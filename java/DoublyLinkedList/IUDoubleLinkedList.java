import java.util.ConcurrentModificationException;
import java.util.Iterator;
import java.util.ListIterator;
import java.util.NoSuchElementException;

/**
 * Double-linked node implementation of IndexedUnsortedList.
 * An Iterator with working remove() method is implemented
 * ListIterator is supported.
 *
 * @author emanuelhernandez
 *
 * @param <T> type to store
 */
public class IUDoubleLinkedList<T> implements IndexedUnsortedList<T> {
    private LinearNode<T> head, tail;
    private int size;
    private int modCount;

    /** Creates an empty list */
    public IUDoubleLinkedList() {
        head = tail = null;
        size = 0;
        modCount = 0;
    }

    @Override
    public void addToFront(T element) {
    	LinearNode<T> firstNewNode = new LinearNode<T>(element);
    	
    	if(isEmpty()){
    		head = firstNewNode;
    		tail = firstNewNode;
    		head.setPrevious(null);
    	}
    	else if(head == tail){
    		LinearNode<T> tempNode = head;
    		firstNewNode.setNext(head);
    		head = firstNewNode;
    		tail = tempNode;
    		tail.setPrevious(head);
    	}
    	else{
	    	firstNewNode.setNext(head);
	    	head = firstNewNode;
	    	head.getNext().setPrevious(head);
    	}
		modCount++;
		size++;
    }

    @Override
    public void addToRear(T element) {
       
    	LinearNode<T> newLastNode = new LinearNode<T>(element);
    	if(isEmpty()){
    		head = newLastNode;
    		tail = newLastNode;
    	}
    	else {
    		tail.setNext(newLastNode);
    		newLastNode.setPrevious(tail);
    		tail = newLastNode;
    	}
    	modCount++;
		size++;
    }

    @Override
    public void add(T element) {
        
    	addToRear(element);
    }

    @Override
    public void addAfter(T element, T target) {
        
    	LinearNode<T> newNode = new LinearNode<T>(element);
    	LinearNode<T> prevNode = null;
    	LinearNode<T> targetNode = head;
    	while(targetNode!=null && targetNode.getElement() != target){
    		prevNode = targetNode;
    		targetNode = targetNode.getNext();
    	}
    	if(targetNode == null) {
    		throw new NoSuchElementException();
    	}
    	if(head==tail){ // first node
    		head.setNext(newNode);
    		tail = newNode;
    		tail.setPrevious(head);
    	}
    	else if(targetNode.getElement() == tail.getElement()){ // last node
    		tail.setNext(newNode);
    		tail = newNode;
    		tail.setPrevious(targetNode);
    	}
    	else { // somewhere in the middle
	    	newNode.setNext(targetNode.getNext());
	    	targetNode.setNext(newNode);
	    	newNode.setPrevious(targetNode);
	    	newNode.getNext().setPrevious(newNode);
    	}
    	modCount++;
    	size++;
    }

    @Override
    public void add(int index, T element) {
        
    	if(index < 0 || index > size){
    		throw new IndexOutOfBoundsException();
    	}
    	LinearNode<T> newNode = new LinearNode<T>(element);
    	if(index == 0){
    		addToFront(element);
    	} else if(index == size){
    		addToRear(element);
    	} else {
    		LinearNode<T> current = head;
    		for(int i = 0; i < index-1; i++){
    			current = current.getNext();
    		}
    		newNode.setNext(current.getNext());
    		current.setNext(newNode);
    		newNode.setPrevious(current);
        	size++;
        	modCount++;
    	}
    }

    @Override
    public T removeFirst() {
        
    	if (isEmpty()) {
            throw new NoSuchElementException();
        }
    	LinearNode<T> retVal = head;
    	if(head == tail){
    		head = tail = null;
    		modCount++;
    		size--;
    		return retVal.getElement();
    	}
    	else{
    		head = head.getNext();
    		head.setPrevious(null);
    		modCount++;
    		size--;
    	}
    	return retVal.getElement();
    }

    @Override
    public T removeLast() {
        
    	if (isEmpty()) {
            throw new NoSuchElementException();
        }
    	
    	if(head == tail){
    		LinearNode<T> retVal = head;
    		head = tail = null;
    		modCount++;
    		size--;
    		return retVal.getElement();
    	}
    	else {
    		LinearNode<T> retVal = tail;
    		tail = tail.getPrevious();
    		tail.setNext(null);
	    	modCount++;
	    	size--;
	        return retVal.getElement();
    	}
    }

    @Override
    public T remove(T element) {
        if (isEmpty()) {
            throw new NoSuchElementException();
        }

        boolean found = false;
        LinearNode<T> previous = null;
        LinearNode<T> current = head;

        while (current != null && !found) {
            if (element.equals(current.getElement())) {
                found = true;
            } else {
                previous = current;
                current = current.getNext();
            }
        }

        if (!found) {
            throw new NoSuchElementException();
        }

        if (size() == 1) { //only node
            head = tail = null;
        } else if (current == head) { //first node
            head = current.getNext();
            //head.setPrevious(null);
        } else if (current == tail) { //last node
            tail = previous;
            tail.setNext(null);
        } else { //somewhere in the middle
        	current.getNext().setPrevious(previous);
            previous.setNext(current.getNext());
        }

        size--;
        modCount++;

        return current.getElement();
    }

    @Override
    public T remove(int index) {
        
    	if(index < 0 || index > size-1){
    		throw new IndexOutOfBoundsException();
    	}
    	LinearNode<T> prevNode = null;
		LinearNode<T> tempNode = head;
		
    	if (size == 1) { //only node
    		T tempElement = head.getElement();
    		head = tail = null;
    		modCount++;
    		size--;
    		return tempElement;
    	} else if (size - 1 == index){ //last node
    		T retVal = tail.getElement();
    		tail = tail.getPrevious();
    		tail.setNext(null);
    		modCount++;
    		size--;
    		return retVal;
    		
    	} else if (index == 0){ //first node
    		T tempHead = head.getElement();
    		head = head.getNext();
    		//head.setPrevious(null);
    		modCount++;
    		size--;
    		return tempHead;
    	} else { // somewhere in the middle
    		for(int i = 0; i < index; i++){
    			prevNode = tempNode;
    			tempNode = tempNode.getNext();
    		}
    		tempNode.getNext().setPrevious(prevNode);
    		prevNode.setNext(tempNode.getNext());
    		modCount++;
    		size--;
    	}
    	return tempNode.getElement();
    }

    @Override
    public void set(int index, T element) {
        
    	if(index < 0 || index > size-1){
    		throw new IndexOutOfBoundsException();
    	}
    	LinearNode<T> currentNode = head;

    	for(int i = 0; i < index; i++){
    		currentNode = currentNode.getNext();
    	}
    	if(currentNode == null){
    		throw new IndexOutOfBoundsException();
    	}
    	currentNode.setElement(element);
    	modCount++;
    }

    @Override
    public T get(int index) {
        
    	if(index < 0 || index > size-1){
    		throw new IndexOutOfBoundsException();
    	}
    	LinearNode<T> tempNode = head;
        for(int i = 0; i < index; i++){
        	tempNode = tempNode.getNext();
        }
        if(tempNode == null){
        	throw new IndexOutOfBoundsException();
        }
        return tempNode.getElement();
    }

    @Override
    public int indexOf(T element) {
        
    	int returnIndex = -1;
    	LinearNode<T> current = head;
    	int currentIndex = 0;
    	while(returnIndex < 0 && current != null) {
    		if(current.getElement().equals(element)){
    			returnIndex = currentIndex;
    		}
    		current = current.getNext();
    		currentIndex++;
    	}
    	return returnIndex;
    }

    @Override
    public T first() {
        
    	if (size == 0) throw new NoSuchElementException();
    	else return head.getElement(); 
    }

    @Override
    public T last() {
    	if (size == 0) throw new NoSuchElementException();
    	else return tail.getElement(); 
    }

    @Override
    public boolean contains(T target) {
    	
    	if(isEmpty()){
    		return false;
    	}
    	LinearNode<T> tempNode = head;
    	if(head == tail){
    		if(tail.getElement() == target){
    			return true;
    		}
    	}
    	while(tempNode != tail.getNext()){
    		if(tempNode.getElement() == target){
    			return true;
    		}
    		else tempNode = tempNode.getNext();
    	}
    	return false;
    }

    @Override
    public boolean isEmpty() {
        if(size == 0) return true;
        else return false;
    }

    @Override
    public int size() {
        return size;
    }

    @Override
    public Iterator<T> iterator() {
        return listIterator();
    }

    @Override
    public ListIterator<T> listIterator() {
    	return new DLLIterator();
    }

    @Override
    public ListIterator<T> listIterator(int startingIndex) {
        return new DLLIterator(startingIndex);
    }

    /** Iterator for IUDoubleLinkedList */
    private class DLLIterator implements ListIterator<T> {
        private LinearNode<T> nextNode;
        private LinearNode<T> lastReturned;
        private LinearNode<T> prevNode;
        private int iterModCount;
        private int nextIndex;
        private boolean checkRemove = false;
        private boolean checkSet = false;

     /** Creates a new iterator for the list */
        public DLLIterator() {
            nextNode = head;
            nextIndex = 0;
            iterModCount = modCount;
        }
        
        public void modCheck(){
			if(iterModCount != modCount){
				throw new ConcurrentModificationException();
			}
		}
        
        public DLLIterator(int startingIndex){
        	if(startingIndex < 0 || startingIndex > size){
        		throw new IndexOutOfBoundsException();
        	}
        	nextNode = head;
        	for(int i = 0; i < startingIndex; i++){
        		prevNode = nextNode;
        		nextNode = nextNode.getNext();
        		checkRemove = false;
        	}
        	nextIndex = startingIndex;
        	iterModCount = modCount;
        	lastReturned = null;
        }
        
        @Override
        public boolean hasNext() {
        	modCheck();
        	if(isEmpty()){
        		return false;
        	}
			if(nextNode != null){
				return true;
			}
			return false;
		}

        @Override
        public T next() {
        	modCheck();
			if(hasNext() == true){
				prevNode = nextNode;
				nextNode = nextNode.getNext();
				checkRemove = true;
				checkSet = true;
				lastReturned = prevNode;
				return prevNode.getElement();
			}
			else {
				throw new NoSuchElementException();
			}
        }

        @Override
        public void remove() {
        	modCheck();

        	if(lastReturned == null){
        		throw new IllegalStateException();
        	}
        if(checkRemove == true){	
        	
        	if(size==1){
        		head=null;
        		tail=null;
        		nextNode=null;
        		prevNode=null;
        	}
        	else if(lastReturned == head){
        		head = head.getNext();
        		head.setPrevious(null);
        	} 

        	else if (lastReturned == tail) {
        		tail = tail.getPrevious();
        		tail.setNext(null);
        	} else{
        		lastReturned.getPrevious().setNext(lastReturned.getNext());
        		lastReturned.getNext().setPrevious(lastReturned.getPrevious());
        	}

        	if(lastReturned == prevNode){
        		prevNode = null;
        	}
        	if(lastReturned == nextNode){
        		nextNode = null;
        	}
        	size--;
        	modCount++;
        	iterModCount++;
        	lastReturned = null;
        	checkRemove=false;
        }
        else if(checkRemove == false){
        		throw new IllegalStateException();
        }
        	else {
        		throw new UnsupportedOperationException();
        	}
        }

		@Override
		public boolean hasPrevious() {
			// TODO Auto-generated method stub
			modCheck();
			return (prevNode != null);
		}

		@Override
		public T previous() {
			// TODO Auto-generated method stub
			modCheck();
			
			if(!hasPrevious()){
				throw new NoSuchElementException();
			}
			
			nextNode = prevNode;
			prevNode = prevNode.getPrevious();
			lastReturned = nextNode;
			checkRemove = true;
			checkSet = true;
	
			nextIndex--;
			return nextNode.getElement();
		}

		@Override
		public int nextIndex() {
			// TODO Auto-generated method stub
			modCheck();
			return nextIndex;
		}

		@Override
		public int previousIndex() {
			// TODO Auto-generated method stub
			modCheck();
			return nextIndex - 1;
		}

		@Override
		public void set(T e) {
			// TODO Auto-generated method stub
			modCheck();
			
			if(!checkSet == false){
			
				if(lastReturned == null){
					throw new IllegalStateException();
				}
				lastReturned.setElement(e);
				checkRemove = false;
				modCount++;
				iterModCount++;
			}
			else throw new IllegalStateException();
		}

		@Override
		public void add(T e) {
			// TODO Auto-generated method stub
			modCheck();
			lastReturned = null;
			LinearNode<T> newNode = new LinearNode<T>(e);
			
			if(isEmpty()){
				head = tail = newNode;
			}
			else if(nextNode == null) {
				tail.setNext(newNode);
				newNode.setPrevious(tail);
				tail = newNode;
			} else if(size == 1){
				prevNode=newNode;
				prevNode.setNext(nextNode);
				nextNode.setPrevious(prevNode);
				head = newNode;
				tail = nextNode;
			}
			else if (nextNode == head){
				newNode.setNext(head);
				head.setPrevious(newNode);
				head = newNode;
				prevNode = head;
			} else {
				prevNode.setNext(newNode);
				newNode.setPrevious(prevNode);
				newNode.setNext(nextNode);
				nextNode.setPrevious(newNode);
			}
			nextNode = newNode;
			checkRemove = false;
			size++;
			modCount++;
			iterModCount++;
		}
    }
    	public String toString(){
    		String str = "[ ";
    		LinearNode<T> tempNode = head;
    		if(!isEmpty()){
    			for(int i = 0; i <= indexOf(tail.getElement()); i++){
    				str += tempNode.getElement() + ", ";
    				tempNode = tempNode.getNext();
    			}
    		}
    		str += "]";
    		return str;
    	}
}
