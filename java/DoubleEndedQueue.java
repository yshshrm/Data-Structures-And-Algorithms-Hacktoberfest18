
class Node {

int data;
Node next;

public Node(int data) {
	this.data = data;
	this.next = null;
	}
}

public class DoubleEndedQueue {

	  private int size=0;
	  private Node front=null;
	  private Node rear=null;
	  private int count=0;
	    DoubleEndedQueue(int count){
	      this.count=count;
	    }
	  public boolean isEmpty(){
			return this.size == 0;
		}
	  
	  public void insertFront(int input)
	  {
	    Node temp=new Node(input);
	    if(front==null && rear==null)
	    {
	      front=temp;
	      rear=temp; 
	      this.size++;
	    }
	    else if(this.size!=count){
	      temp.next=front;
	      front=temp;
	      this.size++;
	    }
	    else
	    {
	      System.out.println("-1");
	      return;
	    }
	    
	   }
	  
	  public void insertRear(int input)
	  {
	    Node temp=new Node(input);
	    if(front==null && rear==null)
	    {
	      front=temp;
	      rear=temp;
	      this.size++;
	    }
	    
	    else if(this.size!=count){
	      rear.next=temp;
	      rear=temp;
	      this.size++;
	    }
	    
	    else{
	      System.out.println("-1");
	      return;
	    }
	    
	  }
	  
	  public void deleteFront()
	  {
	    if(this.size==0){
	      System.out.println("-1");
	      return;}
	    
	    if(this.size==1)
	    {
	      front=null;
	      rear=null;
	      this.size--;
	      return;
	    }

	    front=front.next;
	    
	    this.size--;
	    
	  }
	  
	  public void deleteRear()
	  {
	    Node var=front;
	    if(this.size==0){
	      System.out.println("-1");
	      return;
	    }
	    
	    if(this.size==1)
	    {
	      front=rear=null;
	      this.size--;
	      return;
	    }
	      
	    
	    while(var.next.next!=null)
	    {
	      var=var.next;
	    }
	    var.next=null;
	    rear=var;
	    
	    this.size--;
	    
	    
	  }
	  
	  public int getFront()
	  {
	    if(this.isEmpty())
	      return -1;
	    else
	      return front.data;
	    
	  }
	  
	  public int getRear()
	  {
	    if(this.isEmpty())
	      return -1;
	    else
	      return rear.data;
	    
	  }

}
