package L17_March3;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Scanner;



public class GenericTree {

//    private class Node {
		int data;
		ArrayList<Node> children = new ArrayList<>();
	}

	private Node root;
	private int size;

	public GenericTree() {

		this.root = takeInput(new Scanner(System.in), null, -1);
	}

	public Node takeInput(Scanner scn, Node parent, int ith) {

		// give prompt to user
		if (parent == null) {
			System.out.println("Enter the value for root node ?");
		} else {
			System.out.println("Enter the value for " + ith + " child of " + parent.data);
		}

		// take value of node from user
		int val = scn.nextInt();

		// create a new node
		Node nn = new Node();
		nn.data = val;
		this.size++;

		// prompt for no. of children
		System.out.println("No. of children for " + nn.data + " ?");
		int nc = scn.nextInt();

		// loop on children
		for (int i = 0; i < nc; i++) {

			// take input of each child
			Node child = takeInput(scn, nn, i);

			// attach child with present node
			nn.children.add(child);
		}

		return nn;

	}

	public int size() {
		return this.size;
	}

	public boolean isEmpty() {
		return this.size == 0;
	}

	public void display() {

		System.out.println("----------------------");
		display(this.root);
		System.out.println("----------------------");
	}

	private void display(Node node) {

		String str = node.data + " => ";

		for (int i = 0; i < node.children.size(); i++) {
			str += node.children.get(i).data + ", ";
		}

		str += ".";
		System.out.println(str);

		for (Node child : node.children) {
			display(child);
		}

	}

	public int size2() {
		return size2(this.root);
	}

	private int size2(Node node) {

		int cs = 0;

		for (Node child : node.children) {
			cs += size2(child);
		}

		return cs + 1;
	}

	public int max() {
		return max(this.root);
	}

	private int max(Node node) {

		int sm = node.data;

		for (Node child : node.children) {

			int cm = max(child);

			if (cm > sm) {
				sm = cm;
			}
		}

		return sm;
	}

//    public int second_max_byme(){
//        int[] a=new int[this.size2];
//
//        return second_max_byme(this.root,a);
//    }
//    private int second_max_byme(Node node,int[] a){
//
//
//
//    }
    
      public boolean find(int item) {
		return find(this.root, item);
	}

	private boolean find(Node node, int item) {

		if (node.data == item) {
			return true;
		}

		for (Node child : node.children) {
			boolean res = find(child, item);

			if (res) {
				return true;
			}
		}

		return false;
	}

	public int height() {
		return height(this.root);
	}

	private int height(Node node) {

		int sh = -1;

		for (Node child : node.children) {

			int ch = height(child);

			if (ch > sh) {
				sh = ch;
			}
		}

		return sh + 1;
	}

	public void mirror() {
		mirror(this.root);
	}

	private void mirror(Node node) {

		for (Node child : node.children) {
			mirror(child);
		}

		int left = 0;
		int right = node.children.size() - 1;

		while (left < right) {

			Node ln = node.children.get(left);
			Node rn = node.children.get(right);

			node.children.set(left, rn);
			node.children.set(right, ln);

			left++;
			right--;
		}
	}

	public void preorder() {

		System.out.println("----------------");
		preorder(this.root);
		System.out.println(".");
		System.out.println("----------------");
	}

	private void preorder(Node node) {

		System.out.print(node.data + " ");

		for (Node child : node.children) {
			preorder(child);
		}
	}

	public void postorder() {

		System.out.println("----------------");
		postorder(this.root);
		System.out.println(".");
		System.out.println("----------------");
	}

	private void postorder(Node node) {

		for (Node child : node.children) {
			postorder(child);
		}

		System.out.print(node.data + " ");
	}

	public void traversal() {

		System.out.println("----------------");
		traversal(this.root);
		System.out.println(".");
		System.out.println("----------------");
	}

	private void traversal(Node node) {

		System.out.println("hii " + node.data);

		for (Node child : node.children) {
			System.out.println("going towards " + child.data);
			traversal(child);
			System.out.println("coming back from " + child.data);
		}

		System.out.println("bye " + node.data);
	}

	public void levelorder() {

		LinkedList<Node> queue = new LinkedList<>();
		queue.addLast(this.root);

		while (!queue.isEmpty()) {

			Node rn = queue.removeFirst();
			System.out.println(rn.data);

			for (Node child : rn.children) {
				queue.addLast(child);
			}
		}

	}

	public void levelorderLW() {

		LinkedList<Node> primaryq = new LinkedList<>();
		LinkedList<Node> helperq = new LinkedList<>();
		primaryq.addLast(this.root);

		while (!primaryq.isEmpty()) {

			Node rn = primaryq.removeFirst();
			System.out.print(rn.data + " ");

			for (Node child : rn.children) {
				helperq.addLast(child);
			}

			if (primaryq.isEmpty()) {
				System.out.println();
				primaryq = helperq;
				helperq = new LinkedList<>();
			}
		}

	}

	public void levelorderZZ() {

		int c = 0;
		LinkedList<Node> queue = new LinkedList<>();
		LinkedList<Node> stack = new LinkedList<>();

		queue.addLast(this.root);

		while (!queue.isEmpty()) {

			Node rn = queue.removeFirst();
			System.out.print(rn.data + " ");

			if (c % 2 == 0) {
				for (int i = 0; i < rn.children.size(); i++) {
					stack.addFirst(rn.children.get(i));
				}
			} else {
				for (int i = rn.children.size() - 1; i >= 0; i--) {
					stack.addFirst(rn.children.get(i));
				}
			}

			if (queue.isEmpty()) {
				c++;
				System.out.println();
				queue = stack;
				stack = new LinkedList<>();
			}
		}

	}

	public void multiSolver(int item) {

		HeapMover mover = new HeapMover();
		multiSolver(this.root, mover, item, 0);

		System.out.println("Size : " + mover.size);
		System.out.println("Height : " + mover.height);
		System.out.println("Max : " + mover.max);
		System.out.println("Found : " + mover.found);
		System.out.println("Pred : " + (mover.predecessor == null ? null : mover.predecessor.data));
		System.out.println("Succ : " + (mover.successor == null ? null : mover.successor.data));
		System.out.println("JL : " + (mover.jl == null ? null : mover.jl.data));
	}

	private void multiSolver(Node node, HeapMover mover, int item, int level) {

		mover.size++;

		if (level > mover.height) {
			mover.height = level;
		}

		if (node.data > mover.max) {
			mover.max = node.data;
		}

		if (mover.found == true && mover.successor == null) {
			mover.successor = node;
		}

		if (node.data == item) {
			mover.found = true;
		}

		if (mover.found == false) {
			mover.predecessor = node;
		}

		if (node.data > item) {

			if (mover.jl == null) {
				mover.jl = node;
			} else {
				if (node.data < mover.jl.data) {
					mover.jl = node;
				}
			}
		}
		for (Node child : node.children) {
			multiSolver(child, mover, item, level + 1);
		}

	}

	private class HeapMover {

		int size = 0;
		int height = 0;
		int max = Integer.MIN_VALUE;
		boolean found = false;

		Node predecessor;
		Node successor;

		Node jl;
	}

	private class OrderPair {
		Node node;
		boolean selfDone;
		int childrenDone;
	}

	public void preorderI() {

		System.out.println("----------------");
		LinkedList<OrderPair> stack = new LinkedList<>();
		OrderPair fp = new OrderPair();
		fp.node = this.root;
		stack.addFirst(fp);

		while (!stack.isEmpty()) {

			OrderPair tp = stack.getFirst();

			if (tp.selfDone == false) {
				System.out.print(tp.node.data + " ");
				tp.selfDone = true;
			} else if (tp.childrenDone < tp.node.children.size()) {
				OrderPair np = new OrderPair();
				np.node = tp.node.children.get(tp.childrenDone);
				stack.addFirst(np);

				tp.childrenDone++;

			} else {
				stack.removeFirst();
			}

		}
		System.out.println(".");
		System.out.println("----------------");
	}

}
