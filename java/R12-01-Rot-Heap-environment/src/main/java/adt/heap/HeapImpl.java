package adt.heap;

import java.util.Arrays;
import java.util.Comparator;
import java.util.LinkedList;
import java.util.List;

import util.Util;

/**
 * O comportamento de qualquer heap é definido pelo heapify. Neste caso o
 * heapify dessa heap deve comparar os elementos e colocar o maior sempre no
 * topo. Ou seja, admitindo um comparador normal (responde corretamente 3 > 2),
 * essa heap deixa os elementos maiores no topo. Essa comparação não é feita
 * diretamente com os elementos armazenados, mas sim usando um comparator. Dessa
 * forma, dependendo do comparator, a heap pode funcionar como uma max-heap ou
 * min-heap.
 */
public class HeapImpl<T extends Comparable<T>> implements Heap<T> {

	protected T[] heap;
	protected int index = -1;
	/**
	 * O comparador é utilizado para fazer as comparações da heap. O ideal é mudar
	 * apenas o comparator e mandar reordenar a heap usando esse comparator. Assim
	 * os metodos da heap não precisam saber se vai funcionar como max-heap ou
	 * min-heap.
	 */
	protected Comparator<T> comparator;

	private static final int INITIAL_SIZE = 20;
	private static final int INCREASING_FACTOR = 10;

	/**
	 * Construtor da classe. Note que de inicio a heap funciona como uma min-heap.
	 */
	@SuppressWarnings("unchecked")
	public HeapImpl(Comparator<T> comparator) {
		this.heap = (T[]) (new Comparable[INITIAL_SIZE]);
		this.comparator = comparator;
	}

	// /////////////////// METODOS IMPLEMENTADOS
	private int parent(int i) {
		return (i - 1) / 2;
	}

	/**
	 * Deve retornar o indice que representa o filho a esquerda do elemento indexado
	 * pela posicao i no vetor
	 */
	private int left(int i) {
		return (i * 2 + 1);
	}

	/**
	 * Deve retornar o indice que representa o filho a direita do elemento indexado
	 * pela posicao i no vetor
	 */
	private int right(int i) {
		return (i * 2 + 1) + 1;
	}

	@Override
	public boolean isEmpty() {
		return (index == -1);
	}

	@Override
	public T[] toArray() {
		T[] resp = Util.makeArrayOfComparable(index + 1);
		for (int i = 0; i <= index; i++) {
			resp[i] = this.heap[i];
		}
		return resp;
	}

	// ///////////// METODOS A IMPLEMENTAR
	/**
	 * Valida o invariante de uma heap a partir de determinada posicao, que pode ser
	 * a raiz da heap ou de uma sub-heap. O heapify deve colocar os maiores
	 * (comparados usando o comparator) elementos na parte de cima da heap.
	 */
	private void heapify(int position) {
		if (position >= 0 && position < size()) {
			int largest = position;
			int leftChild = left(position);
			int rightChild = right(position);
			if (leftChild < size() && heap[leftChild] != null
					&& getComparator().compare(heap[leftChild], heap[position]) > 0) {
				largest = leftChild;
			}
			if (rightChild < size() && heap[rightChild] != null
					&& getComparator().compare(heap[rightChild], heap[largest]) > 0) {
				largest = rightChild;
			}
			if (getComparator().compare(heap[largest], heap[position]) != 0) {
				util.Util.swap(getHeap(), largest, position);
				heapify(largest);
			}
		}
	}

	@Override
	public void insert(T element) {
		// ESSE CODIGO E PARA A HEAP CRESCER SE FOR PRECISO. NAO MODIFIQUE
		if (index == heap.length - 1) {
			heap = Arrays.copyOf(heap, heap.length + INCREASING_FACTOR);
		}
		// /////////////////////////////////////////////////////////////////
		if (element != null) {
			index++;
			int i = index;
			while (i > 0 && getComparator().compare(heap[parent(i)], element) < 0) {
				heap[i] = heap[parent(i)];
				i = parent(i);
			}
			heap[i] = element;
		}

	}

	@Override
	public void buildHeap(T[] array) {
		if (array != null) {
			heap = array;
			index = array.length - 1;
			for (int i = array.length / 2; i >= 0; i--) {
				heapify(i);
			}
		}
	}

	@Override
	public T extractRootElement() {
		T result = null;
		if (!isEmpty()) {
			result = heap[0];
			heap[0] = heap[index];
			heap[index] = result;
			index--;
			heapify(0);
		}
		return result;
	}

	@Override
	public T rootElement() {
		if (!isEmpty()) {
			return heap[0];
		}
		return null;
	}

	@Override
	public T[] heapsort(T[] array) {
		T[] result = array;
		if (array.length > 1) {
			buildHeap(array);
			for (int i = array.length - 1; i >= 0; i--) {
				Util.swap(heap, 0, i);
				index--;
				heapify(0);
			}
			result = heap;
			if (heap[0].compareTo(heap[1]) > 0) {
				T[] inverse = util.Util.makeArrayOfComparable(array.length);
				for (int i = 0; i < array.length; i++) {
					inverse[i] = heap[array.length - 1 - i];
				}
				result = inverse;
			}
		}
		return result;
	}

	@Override
	public int size() {
		return index + 1;
	}

	public Comparator<T> getComparator() {
		return comparator;
	}

	public void setComparator(Comparator<T> comparator) {
		this.comparator = comparator;
	}

	public T[] getHeap() {
		return heap;
	}

	@SuppressWarnings("unchecked")
	public T[] mergeArrays(T[] arrayA, T[] arrayB) {
		for (T element : arrayA) {
			insert(element);
		}
		for (T element : arrayB) {
			insert(element);
		}

		T[] aux = (T[]) (new Comparable[size()]);

		for (int index = 0; index < aux.length; index++) {
			aux[index] = extractRootElement();
		}
		return aux;
	}

	public T[] sortLevel(int level) {
		LinkedList<T> aux = new LinkedList<T>();

		if (level >= 0) {
			int startLevel = (int) (Math.pow(2, level) - 1);
			int endLevel = (int) (Math.pow(2, (level + 1)) - 2);

			while (startLevel <= endLevel && heap[startLevel] != null) {
				aux.add(heap[startLevel]);
				startLevel++;
			}
		}

		T[] result = makeArrayFromList(aux);
		Arrays.sort(result);
		return result;
	}

	@SuppressWarnings("unchecked")
	protected T[] makeArrayFromList(List<T> list) {

		int size = list.size();
		T[] array = (T[]) new Comparable[size];
		for (int i = 0; i != size; i++) {
			array[i] = list.get(i);
		}
		return array;
	}
	
	public T[] heapSortMax(T[] array) {
		T[] result = null;
		if (array != null) {
			buildHeap(array);
			for (int i = 1; i < array.length; i++) {
				extractRootElement();
			}
			result = array;
		}
		return result;
	}

}
