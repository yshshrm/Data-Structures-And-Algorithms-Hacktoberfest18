import java.util.ArrayList;
import java.util.Arrays;
import java.util.Random;

public class Lists {


	public static void main(String[] args) {
		
		Lists x=new Lists();
		x.swapFirstLast();
		x.swapPairs();
		x.intersection();
		x.identical();
		x.sortMerge();
		x.greaterOnRight();
		x.evenFirst();
		x.counterClock();
		x.countCircular();
	}
	
	public Node readData()
	{
		Random random=new Random();
		Node start;
		Node X=new Node(random.nextInt(9)+1);
		start=X;
		for(int i=2;i<=10;i++)
		{
			Node Y=new Node(random.nextInt(9)+1);
			X.next=Y;
			X=Y;
		}
		X.next=null;
		return start;
	}
	
	public Node readSortedData()
	{
		Random random=new Random();
		Node start;
		int a[]=new int[10];
		for(int i=0;i<=9;i++)
		{
			a[i]=random.nextInt(10)+1;
		}
		Arrays.sort(a);
		Node X=new Node(a[0]);
		start=X;
		for(int i=1;i<=9;i++)
		{
			Node Y=new Node(a[i]);
			X.next=Y;
			X=Y;
		}
		X.next=null;
		return start;
	}
	
	
	public void swapFirstLast()
	{
		Node start=readData();
		System.out.println("\nSwap First Last\n");
		print(start);
		Node X=start;
		Node Y=X;
		while(X.next!=null)
		{
			Y=X;
			X=X.next;
		}
		System.out.println();
		X.next=start.next;
		
		Y.next=start;
		start.next=null;
		start=X;
		print(start);
	}
	
	public void swapPairs()
	{
		Node start=readData();
		System.out.println("\nPair Wise Swap\n");
		print(start);
		Node X=start;
		Node Y=X.next;
		Node Z=X;
		Node Z1=X;
		while(Y.next!=null)
		{

			if(X==start)
			{
				X.next=Y.next;
				Y.next=X;
				start=Y;
			}
			else
			{
				Z.next=Y;
				X.next=Y.next;
				Y.next=X;
			}
			Z1=X;
			Y=X.next.next;
			Z=X;
			X=X.next;
			
			if(Y==null)
				break;
		}
		if(Y!=null)
		{
			Z.next=Y;
			X.next=null;
			Y.next=X;
		}
		print(start);
	}
	
	public void intersection()
	{
		Node start1=readData();
		Node start2=readData();
		Node X=start1;
		Node start3=null;
		Node Z=start3;
		ArrayList<Integer> a=new ArrayList<Integer>();
		while(X!=null)
		{
			Node Y=start2;
			int exists=0;
			if(a.contains(X.d)==false)
			{
				while(Y!=null)
				{
					if(X.d==Y.d)
					{
						exists=1;
						break;
					}
					Y=Y.next;
				}
				if(exists==1)
				{
					if(start3==null)
					{
						start3=new Node(X.d);
						Z=start3;
					}
					else
					{
						Node Z1=new Node(X.d);
						Z.next=Z1;
						Z=Z1;
					}
					a.add(X.d);
				}
			}
			X=X.next;
		}
		Z.next=null;
		System.out.println("\nIntersection\n");
		print(start1);
		print(start2);
		print(start3);
		
	}
	
	public void identical()
	{
		Node start1=readData();
		Node start2=readData();
		System.out.println("\nIdentical\n");
		print(start1);
		print(start2);
		Node X=start1;
		Node Y=start2;
		int c=0;
		int f=0;
		while(X!=null && Y!=null)
		{
			if(X.d==Y.d)
			{
				f=1;
				c=c+1;
			}
			else
			{
				f=0;
				break;
			}
		}
		if(X==null && Y!=null || X!=null && Y==null)
			f=0;
		
		if(f==1)
			System.out.println("Identical");
		else
			System.out.println("Not Identical");
	}
	
	public void sortMerge()
	{
		Node start1=readSortedData();
		Node start2=readSortedData();
		System.out.println("\nMergeSorting\n");
		print(start1);
		print(start2);
		
		Node start3=new Node(0);
		Node Z=start3;
		Node X=start1,Y=start2;
		while(X!=null || Y!=null)
		{
			if(X==null)
			{
				Z.next=Y;
				break;
			}
			
			if(Y==null)
			{
				Z.next=X;
				break;
			}
			
			if(Y.d<=X.d)
			{
				Z.next=Y;
				Y=Y.next;
			}
			
			else
			{
				Z.next=X;
				X=X.next;
			}
			Z=Z.next;
		}
		Z.next=null;
		Z=start3;
		start3=start3.next;
		Z=null;
		print(start3);
	}
	
	public void greaterOnRight()
	{
		Node start=readData();
		System.out.println("\nDelete Iif greater on right\n");
		print(start);
		Node X=start;
		while(X.next!=null)
		{
			Node Y=X.next;
			int f=0;
			while(Y!=null)
			{
				if(Y.d>X.d)
				{
					f=1;
					break;
				}
				Y=Y.next;
			}
			if(f==1)
			{
				if(X==start)
				{
					start=start.next;
					X=null;
					X=start;
				}
				else
				{
					Node Z=start;
					while(Z.next!=X)
						Z=Z.next;
					Z.next=X.next;
					X=null;
					X=Z.next;
				}
			}
			else
				X=X.next;
		}
		print(start);
	}
	
	public void evenFirst()
	{
		Node start=readData();
		Node X=start;
		System.out.println("\nEven at beginning\n");
		print(start);
		while(X!=null)
		{
			if(X.d%2!=0)
			{
				Node Y=X.next;
				while(Y!=null)
				{
					if(Y.d%2==0)
					{
						int t=X.d;
						X.d=Y.d;
						Y.d=t;
						break;
					}
					Y=Y.next;
				}
			}
			X=X.next;
		}
		print(start);
	}
	
	public void counterClock()
	{
		Node start=readData();
		Node X=start;
		System.out.println("\nRotating counter clockwise\n");
		print(start);
		Random random=new Random();
		int k=random.nextInt(10)+1;
		System.out.println("\nRotating "+k+" times\n");
		Node Y=start;
		
		while(Y.next!=null)
			Y=Y.next;
		
		while(k>0)
		{
			start=start.next;
			Y.next=X;
			X.next=null;
			Y=X;
			X=start;
			k--;
			print(start);
		}
		
		System.out.print("\nFinal Linked List: ");
		print(start);
	}
	
	public void countCircular()
	{
		Node start=readData();
		Node X=start;
		System.out.println("\nCounting Number of Nodes in circular linked list\n");
		Node rear=start;
		while(rear.next!=null)
			rear=rear.next;
		rear.next=start;
		
		int c=0;
		while(X.next!=start)
		{
			c=c+1;
			if(X==start)
				System.out.print("rear->"+X.d+"->");
			else
				System.out.print(X.d+"->");
			X=X.next;
		}
		System.out.println("start\n");
		System.out.println("No. of Nodes in Circular List="+c);
	}
	
	public void print(Node start)
	{
		Node X=start;
		
		while(X.next!=null)
		{
			System.out.print(X.d+"->");
			X=X.next;
		}
		System.out.println(X.d);
	}

}
