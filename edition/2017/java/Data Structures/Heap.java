package Lecture22;

import java.util.ArrayList;

public class Heap<T extends Comparable<T>> {

	private ArrayList<T> data;
	private boolean isMin;

	public Heap() {
		this(false);
	}

	public Heap(boolean isMin) {
		this.data = new ArrayList<>();
		this.isMin = isMin;
	}

	public Heap(T[] items, boolean isMin) {
		this(isMin);

		for (T item : items) {
			this.data.add(item);
		}

		for (int i = this.data.size() / 2 - 1; i >= 0; i--) {
			this.downHeapify(i);
		}
	}

	public int size() {
		return this.data.size();
	}

	public boolean isEmpty() {
		return this.data.size() == 0;
	}

	public void display() {
		this.displayNode(0);
	}

	private void displayNode(int idx) {
		int lci = 2 * idx + 1;
		int rci = 2 * idx + 2;

		String str = " ";

		if (lci < this.data.size()) {
			T lc = this.data.get(lci);
			str = lc + " => ";
		} else {
			str = "END => ";
		}

		T node = this.data.get(idx);
		str += node;

		if (rci < this.data.size()) {
			T rc = this.data.get(rci);
			str += " <= " + rc;
		} else {
			str += " <= END";
		}

		System.out.println(str);

		if (lci < this.data.size()) {
			this.displayNode(lci);
		}

		if (rci < this.data.size()) {
			this.displayNode(rci);
		}

	}

	public T getHP() {
		return this.data.get(0);
	}

	public void add(T item) {
		this.data.add(item);

		upHeapify(this.data.size() - 1);

	}

	private void upHeapify(int ci) {
		if (ci == 0) {
			return;
		}

		int pi = (ci - 1) / 2;

		if (!isLarger(pi, ci)) {
			this.swap(pi, ci);
			this.upHeapify(pi);
		}
	}

	public T remove() {
		T rv = this.data.get(0);
		this.swap(0, this.data.size() - 1);
		this.data.remove(this.data.size() - 1);

		downHeapify(0);

		return rv;
	}

	private void downHeapify(int pi) {
		int lci = 2 * pi + 1;
		int rci = 2 * pi + 2;

		int mi = pi;

		if (lci < this.data.size() && isLarger(lci, mi)) {
			mi = lci;
		}

		if (rci < this.data.size() && isLarger(rci, mi)) {
			mi = rci;
		}
		if (pi != mi) {
			swap(mi, pi);
			downHeapify(mi);
		}
	}

	private void swap(int i, int j) {
		T temp = this.data.get(i);
		this.data.set(i, this.data.get(j));
		this.data.set(j, temp);
	}

	private boolean isLarger(int i, int j) {
		T one = this.data.get(i);
		T two = this.data.get(j);

		if (this.isMin) {
			return one.compareTo(two) < 0;
		} else {
			return one.compareTo(two) > 0;
		}
	}
}
