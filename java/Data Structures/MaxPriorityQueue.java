import java.util.Comparator;
import java.util.NoSuchElementException;

public class MaxPriorityQueue<V> {
    private static final int DEFAULT_SIZE = 8;

    private V[] elements;
    private int elementsCount;
    private Comparator<V> comparator;

    public MaxPriorityQueue() {
        this(DEFAULT_SIZE);
    }

    public MaxPriorityQueue(int length) {
        elements = (V[]) new Object[length + 1];
        elementsCount = 0;
    }

    public MaxPriorityQueue(Comparator<V> comparator) {
        this(DEFAULT_SIZE, comparator);
    }

    public MaxPriorityQueue(int length, Comparator<V> comparator) {
        this(length);
        this.comparator = comparator;
    }

    public MaxPriorityQueue(V[] elements) {
        this(elements.length);
        elementsCount = elements.length;
        for (int i = 0; i < elementsCount; i++) {
            this.elements[i + 1] = elements[i];
        }

        for (int sinkElementIndex = elementsCount / 2; sinkElementIndex >= 1; sinkElementIndex--) {
            sink(sinkElementIndex);
        }
        assert isMaxHeap();
    }

    public void enqueue(V value) {
        if (elementsCount >= elements.length - 1) {
            resize(2 * elements.length);
        }
        elements[++elementsCount] = value;
        swim(elementsCount);
        assert isMaxHeap();
    }

    public V dequeue() {
        if (isEmpty()) {
            throw new NoSuchElementException();
        }
        V result = elements[1];
        swap(1, elementsCount--);
        sink(1);
        elements[elementsCount + 1] = null;
        assert isMaxHeap();
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
        while (elementIndex > 1 && less(elementIndex / 2, elementIndex)) {
            swap(elementIndex, elementIndex / 2);
            elementIndex /= 2;
        }
    }

    private void sink(int elementIndex) {
        while (2 * elementIndex <= elementsCount) {
            int greaterChildIndex = 2 * elementIndex;
            if (greaterChildIndex < elementsCount && less(greaterChildIndex, greaterChildIndex + 1)) {
                greaterChildIndex++;
            }

            if (!less(elementIndex, greaterChildIndex)) {
                break;
            }
            swap(elementIndex, greaterChildIndex);
            elementIndex = greaterChildIndex;
        }
    }

    private void resize(int newLength) {
        V[] newElements = (V[]) new Object[newLength];
        for (int i = 1; i <= elementsCount; i++) {
            newElements[i] = elements[i];
        }
        elements = newElements;
    }

    private boolean less(int i, int j) {
        if (comparator == null) {
            return ((Comparable<V>) elements[i]).compareTo(elements[j]) < 0;
        } else {
            return comparator.compare(elements[i], elements[j]) < 0;
        }
    }

    private void swap(int i, int j) {
        V swap = elements[i];
        elements[i] = elements[j];
        elements[j] = swap;
    }

    private boolean isMaxHeap() {
        return isMaxHeap(1);
    }

    private boolean isMaxHeap(int parentIndex) {
        if (parentIndex > elementsCount) {
            return true;
        }

        int leftChildIndex = 2 * parentIndex;
        int rightChildIndex = 2 * parentIndex + 1;
        boolean leftChildGreaterThanParent = leftChildIndex <= elementsCount && less(parentIndex, leftChildIndex);
        boolean rightChildGreaterThanParent = rightChildIndex <= elementsCount && less(parentIndex, rightChildIndex);

        if (leftChildGreaterThanParent || rightChildGreaterThanParent) {
            return false;
        }

        return isMaxHeap(leftChildIndex) && isMaxHeap(rightChildIndex);
    }
}
