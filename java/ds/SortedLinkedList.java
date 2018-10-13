import java.util.Objects;
import java.util.function.Consumer;

public class SortedLinkedList<T extends Comparable<T>>
{
	private static class Node<T extends Comparable<T>> implements Comparable<Node<T>>
	{
		private T _data;
		private Node<T> _previous;
		private Node<T> _next;
		
		public Node() {}
		
		public Node(T data)
		{
			_data = data;
		}
		
		public T getData()
		{
			return _data;
		}
		
		public Node<T> getPrevious()
		{
			return _previous;
		}
		
		public Node<T> getNext()
		{
			return _next;
		}
		
		@Override
		public int compareTo(Node<T> o)
		{
			if (_data == null)
			{
				if (o == null || o.getData() == null)
				{
					return 0;
				}
				return 1;
			}
			if (o == null || o.getData() == null)
			{
				return -1;
			}
			return _data.compareTo(o.getData());
		}
		
		public void setData(T data)
		{
			_data = data;
		}
		
		public void setPrevious(Node<T> node)
		{
			_previous = node;
		}
		
		public void setNext(Node<T> node)
		{
			_next = node;
		}
		
		public static <T extends Comparable<T>> void swap(Node<T> n1, Node<T> n2)
		{
			T d1 = n1.getData();
			n1.setData(n2.getData());
			n2.setData(d1);
		}
	}
	
	private Node<T> _head = new Node<>();
	private Node<T> _tail = _head;
	private int _size = 0;
	
	public SortedLinkedList() {}
	
	private int partition(Node<T>[] arr, int low, int high)
	{
		Node<T> pivot = arr[high];  

		int i = (low - 1);

		for (int j = low; j < high; j++)
		{
			if (arr[j].compareTo(pivot) <= 0)
			{
				i++;
				Node.swap(arr[i], arr[j]);
			}
		}
		Node.swap(arr[i + 1], arr[high]);
		return (i + 1);
	}
	
	private void quickSort(Node<T>[] arr, int low, int high)
	{
		if (low < high)
		{
			int pi = partition(arr, low, high);

			quickSort(arr, low, pi - 1);  // Before pi
			quickSort(arr, pi + 1, high); // After pi
		}
	}
	
	@SuppressWarnings("unchecked")
	private void sort()
	{
		Node<T>[] arr = new Node[_size];
		
		Node<T> node = _head;
		for (int i = 0; i < _size; i++)
		{
			arr[i] = node;
			node = node.getNext();
		}
		
		quickSort(arr, 0, _size - 1);
	}
	
	public int getSize()
	{
		return _size;
	}
	
	public boolean isEmpty()
	{
		return _size == 0;
	}
	
	public boolean contains(T obj)
	{
		Objects.requireNonNull(obj);
		
		if (_size == 0)
		{
			return false;
		}
		
		if (_size == 1 && obj.equals(_head.getData()))
		{
			return true;
		}
		
		Node<T> node = _head.getNext();
		while (node != null)
		{
			if (obj.equals(node.getData()))
			{
				return true;
			}
			node = node.getNext();
		}
		
		return false;
	}
	
	private void add(T obj, boolean sort)
	{
		Objects.requireNonNull(obj);
		
		boolean needsSort = false;
		if (_size == 0)
		{
			_head.setData(obj);
		}
		else
		{
			Node<T> next = new Node<>(obj);
			_tail.setNext(next);
			next.setPrevious(_tail);
			_tail = next;
			
			if (_tail.compareTo(_tail.getPrevious()) <= 0)
			{
				needsSort = true;
			}
		}
		
		_size++;
		if (needsSort && sort)
		{
			sort();
		}
	}
	
	public void add(T obj)
	{
		add(obj, true);
	}
	
	@SuppressWarnings("unchecked")
	public void addElements(T... arr)
	{
		for (T obj : arr)
		{
			add(obj, false);
		}
		if (arr.length > 0)
		{
			sort();
		}
	}
	
	public T poll()
	{
		if (_size == 0)
		{
			return null;
		}
		
		T data;
		if (_size == 1)
		{
			data = _head.getData();
			_head.setData(null);
		}
		else
		{
			data = _tail.getData();
			_tail.setData(null);
			_tail.getPrevious().setNext(null);
			_tail = _tail.getPrevious();
		}
		
		_size--;
		return data;
	}
	
	public T removeFirst()
	{
		if (_size == 0)
		{
			return null;
		}
		
		T data;
		if (_size == 1)
		{
			data = _head.getData();
			_head.setData(null);
		}
		else
		{
			data = _head.getData();
			
			_head = _head.getNext();
		}
		
		_size--;
		return data;
	}
	
	public boolean removeElement(T obj, boolean all)
	{
		Objects.requireNonNull(obj);
		
		if (_size == 0)
		{
			return false;
		}
		
		if (_size == 1 && obj.equals(_head.getData()))
		{
			removeFirst();
			return true;
		}
		
		boolean found = false;
		Node<T> node = _head.getNext();
		while (node != null)
		{
			if (obj.equals(node.getData()))
			{
				found = true;
				
				node.getPrevious().setNext(node.getNext());
				if (node.getNext() != null)
				{
					node.getNext().setPrevious(node.getPrevious());
				}
				_size--;
				
				if (!all)
				{
					return true;
				}
			}
			node = node.getNext();
		}
		
		return found;
	}
	
	public void forEach(Consumer<T> consumer)
	{
		Node<T> node = _head;
		while (node != null)
		{
			if (node.getData() != null)
			{
				consumer.accept(node.getData());
			}
			node = node.getNext();
		}
	}
	
	@Override
	public String toString()
	{
		StringBuilder sb = new StringBuilder("SortedLinkedList{size=" + _size + ",elements=[");
		if (_size > 0)
		{
			forEach(d -> sb.append(d.toString()).append(','));
			sb.setLength(sb.length() - 1);
		}
		sb.append("]}");
		
		return sb.toString();
	}
}
