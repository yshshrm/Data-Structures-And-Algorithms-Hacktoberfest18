public class Stack{
	
    int arr[];
    
    int size;
    
    public Stack(int size) {
        arr = new int[size];
        this.size = 0;
    }
    
    public boolean isEmpty(){ return size == 0; }
    
    public int top() throws StackEmptyException{
    	if(isEmpty())
    		throw new StackEmptyException();
    	return arr[size - 1];
    }
    
    public int size(){ return size; }
    
    public void push(int element) throws StackFullException {
    	if(size == arr.length)
    		throw new StackFullException();
        arr[size++] = element;
    }
    
    public int pop() throws StackEmptyException {
    	if(isEmpty())
    		throw new StackEmptyException();
        return arr[--size];
    }
}

class StackFullException extends Exception{}

class StackEmptyException extends Exception{}
