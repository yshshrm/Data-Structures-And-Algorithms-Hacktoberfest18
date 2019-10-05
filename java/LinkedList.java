package march16;

public class LinkedList {
	private class Node {
		public int data;
		public Node next;
	}

	private Node rdrLeft;
	private Node head;
	private Node tail;
	private int size;

	private Node getNodeAt(int idx) {
		Node temp = head;
		for (int i = 0; i < idx; i++) {
			temp = temp.next;
		}
		return temp;
	}

	private void handleAddLastsize0(int data) {
		Node nn = new Node();
		nn.data = data;
		nn.next = null;

		tail = nn;
		head = nn;
		size++;
	}

	private int handleatsize1() {

		int temp = head.data;
		head = tail = null;
		size = 0;
		return temp;
	}

	public void display() {
		Node temp = head;
		for (int i = 0; i < size; i++) {
			System.out.print(temp.data + " ");
			temp = temp.next;
		}
		System.out.println();
	}

	public int getSize() {
		return size;
	}

	public boolean isEmpty() {
		return size == 0;
	}

	public void addFirst(int data) {
		if (size == 0) {
			handleAddLastsize0(data);
		} else {
			Node n1 = new Node();
			n1.data = data;
			n1.next = head;

			head = n1;

			size++;
		}
	}

	public void addLast(int data) {
		if (size == 0) {
			handleAddLastsize0(data);
		} else {
			Node nn = new Node();
			nn.data = data;
			nn.next = null;

			tail.next = nn;
			tail = nn;
			size++;
		}
	}

	public void addAt(int data, int idx) {
		if (idx < 0 || idx > size) {
			System.out.println("Wrong Index");
		} else if (idx == 0) {
			addFirst(data);
		} else if (idx == size) {
			addLast(data);
		} else {
			Node nm1 = getNodeAt(idx - 1);
			Node nm2 = getNodeAt(idx);

			Node nc = new Node();
			nc.data = data;
			nc.next = nm2;

			nm1.next = nc;

			size++;
		}

	}

	public int getFirst() {
		if (size == 0) {
			return -1;
		} else {
			return head.data;
		}
	}

	public int getLast() {
		if (size == 0) {
			return -1;
		} else {
			return tail.data;
		}
	}

	public int getAt(int idx) {
		if (idx < 0 || idx > size) {
			return -1;
		} else {
			Node nm1 = getNodeAt(idx);
			return nm1.data;
		}
	}

	public int removeFirst() {
		if (size == 0) {
			return -1;
		} else if (size == 1) {
			return handleatsize1();
		} else {
			Node n1 = head;
			int temp = n1.data;
			head = n1.next;
			size--;
			return temp;
		}
	}

	public int removeLast() {
		if (size == 1) {
			return handleatsize1();
		} else {
			Node nm1 = getNodeAt(size - 2);
			nm1.next = null;

			int temp = tail.data;
			tail = nm1;
			size--;
			return temp;
		}
	}

	public int removeAt(int idx) {
		if (idx < 0 || idx >= size) {
			return -1;
		} else if (idx == 0) {
			return removeFirst();
		} else if (idx == size - 1) {
			return removeLast();
		} else {
			Node nm1 = getNodeAt(idx - 1);
			Node nc = nm1.next;
			Node np1 = nc.next;

			int temp = nc.data;

			nm1.next = np1;
			size--;
			return temp;

		}
	}

	public void revData() {

		for (int i = 0, j = size - 1; i <= j; i++, j--) {
			int temp = getNodeAt(i).data;
			getNodeAt(i).data = getNodeAt(j).data;
			getNodeAt(j).data = temp;
		}
	}

	public void revPointer() {
		Node p = null;
		Node c = head;
		Node n = c.next;

		while (c != null) {
			c.next = p;
			p = c;
			c = n;
			if (n != null) {
				n = n.next;
			}

		}

		Node temp = head;
		temp.next = null;
		head = tail;
		tail = temp;
	}

	private void Disprev(Node node) {
		if (node.next == null) {
			System.out.print(node.data + " ");
			return;
		}
		Disprev(node.next);
		System.out.print(node.data + " ");
	}

	public void dispRev() {
		Disprev(head);
		System.out.println();
	}

	private void RevPointRecursion(Node node) {
		if (node.next == null) {
			return;
		}
//		Node p = node;
		Node nn = node.next;
		RevPointRecursion(node.next);
		nn.next = node;

	}

	public void revPointRecursion() {

		RevPointRecursion(head);
		Node temp = head;
		temp.next = null;
		head = tail;
		tail = temp;

		tail.next = null;
	}

	private void RevDataRecursion(Node right, int floor) {
		if (right == null) {
			return;
		}
		RevDataRecursion(right.next, floor + 1);
		if (floor >= size / 2) {
			int temp = rdrLeft.data;
			rdrLeft.data = right.data;
			right.data = temp;
		}
		rdrLeft = rdrLeft.next;
	}

	public void revDataRecursion() {
		rdrLeft = head;
		RevDataRecursion(head, 0);
	}

	private boolean IsPalindrome(Node right, int floor) {
		if (right == null) {
			return true;
		}
		boolean x = IsPalindrome(right.next, floor + 1);
		if (x == false) {
			return false;
		}
		if (floor >= size / 2) {
			if (rdrLeft.data != right.data) {
				return false;
			}
		}

		rdrLeft = rdrLeft.next;
		return true;
	}

	public boolean IsPalindrome() {
		rdrLeft = head;
		return IsPalindrome(head, 0);
	}

	private void fold(Node right, int floor) {
		if (right == null) {
			return;
		}
		fold(right.next, floor + 1);
		if (floor > size / 2) {
			right.next = rdrLeft.next;
			rdrLeft.next = right;
			rdrLeft = rdrLeft.next.next;
		} else if (floor == size / 2) {
			tail = right;
			right.next = null;
			return;
		}

	}

	public void fold() {
		rdrLeft = head;
		fold(head, 0);
		return;
	}

	private void unfold(Node left) {
		if (left.next == null) {
			head = tail = left;
			return;
		} else if (left.next.next == null) {
			head = left;
			tail = left.next;
			return;
		}
		Node right = left.next;
		unfold(left.next.next);
		left.next = head;
		tail.next = right;
		head = left;
		tail = right;
		tail.next = null;
	}

	public void unfold() {
		unfold(head);
	}

	private Node RemoveFirstNode() {
		if (size == 0) {
			return null;
		} else if (size == 1) {
			Node n1 = head;
			head = tail =null;
			size--;
			return n1;
		} else {
			Node n1 = head;
			head = n1.next;
			size--;
			n1.next = null;
			return n1;
		}
	}
	
	private void AddFirstNode(Node n1) {
		if (size == 0) {
			n1.next =null;

			tail = n1;
			head = n1;
			size++;
		} else {
			
			n1.next = head;
			head = n1;
			size++;
		}
	}
	
	public void kReverse(int k) {
		LinkedList pre = null;
		while (this.size != 0) {
			LinkedList cur = new LinkedList();
			for (int i = 0; i < k && this.size>0; i++) {
				cur.AddFirstNode((this.RemoveFirstNode()));
			}
			if (pre == null) {
				pre = cur;
			} else {
				pre.tail.next = cur.head;
				pre.tail = cur.tail;
				pre.size += cur.size;

			}

		}
		this.head = pre.head;
		this.tail = pre.tail;
		this.size = pre.size;
	}
	private void addLastNode(Node nn) {
		if(size == 0) {
			nn.next = null;
			tail = nn;
			head = nn;
			size++;
		}
		else {
			nn.next = null;
			tail.next = nn;
			tail = nn;
			size++;
		}
	}
	public void oddEven() {
		LinkedList even = new LinkedList();
		LinkedList odd = new LinkedList();
		while(size!=0) {
			Node nn = this.RemoveFirstNode();
			if(nn.data % 2 ==0) {
				even.addLastNode(nn);
			}
			else {
				odd.addLastNode(nn);
			}
		}
		if(odd.size == 0) {
			this.size = odd.size;
			this.head = odd.head;
			this.tail = odd.tail;
		}
		else if(even.size == 0) {
			this.size = even.size;
			this.head = even.head;
			this.tail = even.tail;
		}
		else {
			odd.tail.next = even.head;
			odd.tail = even.tail;
			this.size = odd.size + even.size;
			this.head = odd.head;
			this.tail = odd.tail;
		}		
	}
	
	public void removeDuplicate() {
		LinkedList nl = new LinkedList();
		while(this.size!=0) {
			Node nn = this.RemoveFirstNode();
			if(nl.size==0 || nl.tail.data != nn.data) {
				nl.addLastNode(nn);
			}
		}
		this.head = nl.head;
		this.tail = nl.tail;
		this.size = nl.size;
	}

}