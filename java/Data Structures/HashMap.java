import java.util.ArrayList;

public class CustomizeHashMap<K, V> {
	ArrayList<MapNode<K, V>> bucket;
	int bucketSize;
	int noOfEntries;

	public CustomizeHashMap() {
		bucket = new ArrayList<>();
		bucketSize = 10;
		for (int i = 0; i < bucketSize; i++) {
			bucket.add(null);
		}
		noOfEntries = 0;
	}

	public void put(K key, V value) {
		int index = getIndex(key);
		MapNode<K, V> head = bucket.get(index);

		while (head != null) {
			if (head.key.equals(key)) {
				head.value = value;
				return;
			}
			head = head.next;
		}
		MapNode<K, V> nyaNode = new MapNode<>(key, value);
		nyaNode.next = bucket.get(index);
		noOfEntries++;
		bucket.set(index, nyaNode);

		if ((noOfEntries * (1.0)) / bucketSize > .7) {
			rehash();
		}
	}

	
	
	
	private void rehash() {
		ArrayList<MapNode<K, V>> temp = bucket;
		bucketSize = bucketSize * 2;
		bucket = new ArrayList<>();
		for (int i = 0; i < bucketSize; i++) {
			bucket.add(null);
		}
		noOfEntries = 0;
		for (MapNode<K, V> head : temp) {
			while (head != null) {
				put(head.key, head.value);
				head = head.next;
			}
		}
	}

	private int getIndex(K key) {
		int hashCode = key.hashCode();
		return compress(hashCode);
	}
	
	private int compress(int hashCode) {
		return hashCode % bucketSize;
	}

	public V get(K key) {
		int index = getIndex(key);
		MapNode<K, V> head = bucket.get(index);

		while (head != null) {
			if (head.key.equals(key)) {
				return head.value;
			}
			head = head.next;
		}
		return null;
	}

	
	
	public boolean remove(K key) {

		int index = getIndex(key);
		MapNode<K, V> head = bucket.get(index);

		if (head.key.equals(key)) {
			bucket.set(index, head.next);
			noOfEntries--;
			return true;
		}

		while (head != null) {
			if (head.next.key.equals(key)) {
				head.next = head.next.next;
				noOfEntries--;
				return true;
			}
			head = head.next;
			if (head.next == null) {
				break;
			}
		}
		return false;
	}

	public boolean isEmpty() {
		return noOfEntries == 0 ? true : false;
	}

	public int size() {
		return noOfEntries;
	}

	public ArrayList<K> getKeys() {
		ArrayList<K> keys = new ArrayList<>();
		for (MapNode<K, V> head : bucket) {
			while (head != null) {
				keys.add(head.key);
				head = head.next;
			}
		}
		return keys;
	}

}
