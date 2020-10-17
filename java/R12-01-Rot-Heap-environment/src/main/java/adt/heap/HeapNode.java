package adt.heap;

public class HeapNode<T> implements Comparable<HeapNode> {
	
	public long time;
	T data;
	
	public HeapNode(T element, long id){
		data = element;
		time = id;
	}

	public T getData() {
		return data;
	}

	public void setData(T data) {
		this.data = data;
	}

	public long getTime() {
		return time;
	}

	@Override
	public int compareTo(HeapNode o) {
		return (int) (time - o.getTime());
	}



}
