import java.util.Comparator;
import java.util.NoSuchElementException;

public class MinPriorityQueue<V> {
    private static final int DEFAULT_SIZE = 8;

    private V[] elements;
    private int elementsCount;
    private Comparator<V> comparator;

    public MinPriorityQueue() {
        this(DEFAULT_SIZE);
    }

    public MinPriorityQueue(int length) {
        elements = (V[]) new Object[length + 1];
        elementsCount = 0;
    }

    public MinPriorityQueue(Comparator<V> comparator) {
        this(DEFAULT_SIZE, comparator);
    }

    public MinPriorityQueue(int length, Comparator<V> comparator) {
        this(length);
        this.comparator = comparator;
    }

    public MinPriorityQueue(V[] elements) {
        this(elements.length);
        elementsCount = elements.length;
        for (int i = 0; i < elementsCount; i++) {
            this.elements[i + 1] = elements[i];
        }

        for (int sinkElementIndex = elementsCount / 2; sinkElementIndex >= 1; sinkElementIndex--) {
            sink(sinkElementIndex);
        }
        assert isMinHeap();
    }

    public void enqueue(V value) {
        if (elementsCount >= elements.length - 1) {
            resize(2 * elements.length);
        }
        elements[++elementsCount] = value;
        swim(elementsCount);
        assert isMinHeap();
    }

    public V dequeue() {
        if (isEmpty()) {
            throw new NoSuchElementException();
        }
        V result = elements[1];
        swap(1, elementsCount--);
        sink(1);
        elements[elementsCount + 1] = null;
        assert isMinHeap();
        return result;
    }

    public V peek() {
        if (isEmpty()) {
            throw new NoSuchElementException();
        }
        return elements[1];
    }

    public int size() {
        return elementsCount;
    }

    public boolean isEmpty() {
        return elementsCount == 0;
    }

    private void swim(int elementIndex) {
        while (elementIndex > 1 && greater(elementIndex / 2, elementIndex)) {
            swap(elementIndex, elementIndex / 2);
            elementIndex /= 2;
        }
    }

    private void sink(int elementIndex) {
        while (2 * elementIndex <= elementsCount) {
            int smallerChildIndex = 2 * elementIndex;
            if (smallerChildIndex < elementsCount && greater(smallerChildIndex, smallerChildIndex + 1)) {
                smallerChildIndex++;
            }

            if (!greater(elementIndex, smallerChildIndex)) {
                break;
            }
            swap(elementIndex, smallerChildIndex);
            elementIndex = smallerChildIndex;
        }
    }

    private void resize(int newLength) {
        V[] newElements = (V[]) new Object[newLength];
        for (int i = 1; i <= elementsCount; i++) {
            newElements[i] = elements[i];
        }
        elements = newElements;
    }

    private boolean greater(int i, int j) {
        if (comparator == null) {
            return ((Comparable<V>) elements[i]).compareTo(elements[j]) > 0;
        } else {
            return comparator.compare(elements[i], elements[j]) > 0;
        }
    }

    private void swap(int i, int j) {
        V swap = elements[i];
        elements[i] = elements[j];
        elements[j] = swap;
    }

    private boolean isMinHeap() {
        return isMinHeap(1);
    }

    private boolean isMinHeap(int parentIndex) {
        if (parentIndex > elementsCount) {
            return true;
        }

        int leftChildIndex = 2 * parentIndex;
        int rightChildIndex = 2 * parentIndex + 1;
        boolean leftChildLessThanParent = leftChildIndex <= elementsCount && greater(parentIndex, leftChildIndex);
        boolean rightChildLessThanParent = rightChildIndex <= elementsCount && greater(parentIndex, rightChildIndex);

        if (leftChildLessThanParent || rightChildLessThanParent) {
            return false;
        }

        return isMinHeap(leftChildIndex) && isMinHeap(rightChildIndex);
    }
}
