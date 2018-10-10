
class QueueEmptyException extends Exception{
	
}
 class Node <T>{
	T data;
	Node<T> next;
	public Node(T data) {
		this.data=data;
	}
}

public class queueUsingLL<T> {

	Node<T> front;
	Node<T> rear;
	int size;
	public queueUsingLL() {
		front=null;
		rear=null;
		size=0;
	}
	
	public void enqueue(T data) {
		
		Node<T> newNode=new Node(data);	
		if(front==null&&rear==null) {
			front=newNode;
			rear=newNode;
		}else {
			rear.next=newNode;
			rear=newNode;
		}
		size++;
		
		
	}
	
	public T dequeue() throws QueueEmptyException{
		if(size==0) {
			throw new QueueEmptyException();
		}
		
		T temp=front.data;
		front=front.next;
		size--;
		return temp;
		
		
	}
	
	public boolean isEmpty(){
		
		if(size==0) 
			return true;
		else
			return false;
		
	}
	
	public int size() {
		return size;
	}
	
	public T front() throws QueueEmptyException{
		if(size==0) {
			throw new QueueEmptyException();
		}
		
		return front.data;
		
		
	}
	
}
