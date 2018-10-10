//Push in O(1); Pop and Top in O(n)
public class StackUsingQueues{
	DynamicQueue dataQueue;
	DynamicQueue helperQueue;
	
	public StackUsingQueues(int cap) {
		dataQueue = new DynamicQueue(cap);
		helperQueue = new DynamicQueue(cap);
	}
	
	//O(1)
	public void push(int val){
		dataQueue.enqueue(val);
	}
	
	//O(n)
	public int pop(){
		
		if(dataQueue.size() == 0){
			System.out.println("Stack Underflow!");
			return -1;
		}
		
		
		while(dataQueue.size()>1){
			helperQueue.enqueue(dataQueue.dequeue());
		}
		
		int rv = dataQueue.dequeue();
		dataQueue = helperQueue;
		helperQueue = new DynamicQueue(dataQueue.size());
		
		return rv;
	}
	
	
	//O(n)
	public int top(){
		if(dataQueue.size() == 0){
			System.out.println("Stack Underflow!");
			return -1;
		}
		
		while(dataQueue.size()!=1){
			helperQueue.enqueue(dataQueue.dequeue());
		}
		
		int rv = dataQueue.dequeue();
		helperQueue.enqueue(rv);
		dataQueue = helperQueue;
		helperQueue = new DynamicQueue(dataQueue.size());
		
		return rv;
	}
	
	public void display(){
		dataQueue.display();
	}
	
}
