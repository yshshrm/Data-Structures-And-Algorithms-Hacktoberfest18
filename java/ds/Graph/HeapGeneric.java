package Graph;

import java.util.ArrayList;
import java.util.HashMap;



public class HeapGeneric<T extends Comparable<T>> {

	ArrayList<T> data = new ArrayList<>();
	HashMap<T, Integer> map = new HashMap<>();

	public void add(T item) {

		data.add(item);
		map.put(item, this.data.size() - 1);
		upheapify(this.data.size() - 1);
	}

	private void upheapify(int ci) {

		int pi = (ci - 1) / 2;

		if (isLarger(this.data.get(ci), this.data.get(pi)) > 0) {
			swap(pi, ci);
			upheapify(pi);
		}

	}

	private void swap(int i, int j) {

		T ith = data.get(i);
		T jth = data.get(j);

		data.set(i, jth);
		data.set(j, ith);

		map.put(ith, j);
		map.put(jth, i);
	}

	public T remove() {

		swap(0, data.size() - 1);

		T rv = data.remove(data.size() - 1);
		map.remove(rv);
		downheapify(0);

		return rv;
	}

	private void downheapify(int pi) {

		int lci = 2 * pi + 1;
		int rci = 2 * pi + 2;
		int mini = pi;

		if (lci < this.data.size() && isLarger(data.get(lci), data.get(mini)) > 0) {
			mini = lci;
		}

		if (rci < this.data.size() && isLarger(data.get(rci), data.get(mini)) > 0) {
			mini = rci;
		}

		if (mini != pi) {
			swap(mini, pi);
			downheapify(mini);
		}
	}

	public T get() {
		return this.data.get(0);
	}

	public void display() {
		System.out.println(data);
	}

	public int size() {
		return this.data.size();
	}

	public boolean isEmpty() {
		return this.size() == 0;
	}

	public int isLarger(T t, T o) {
		return t.compareTo(o);
	}

	public void updatePriority(T nbrPair) {

		// int idx = -1;
		//
		// for (int i = 0; i < this.data.size(); i++) {
		// if (this.data.get(i) == nbrPair) {
		// idx = i;
		// }
		// }

		int idx = map.get(nbrPair);
		upheapify(idx);

	}
}
