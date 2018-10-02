package L21_March11;


public class BST {

	private class Node {
		int data;
		Node left;
		Node right;
	}

	private Node root;
	private int size;

	public BST(int[] in) {
		this.root = construct(in, 0, in.length - 1);
	}

	private Node construct(int[] in, int lo, int hi) {

		if (lo > hi)
			return null;

		int mid = (lo + hi) / 2;

		Node nn = new Node();
		nn.data = in[mid];
		this.size++;

		nn.left = construct(in, lo, mid - 1);
		nn.right = construct(in, mid + 1, hi);

		return nn;
	}

	public void display() {
		System.out.println("---------------");
		display(this.root);
		System.out.println("---------------");
	}

	private void display(Node node) {

		if (node == null)
			return;

		// self work
		String str = "";

		if (node.left == null) {
			str += ".";
		} else {
			str += node.left.data;
		}

		str += " => " + node.data + " <= ";

		if (node.right == null) {
			str += ".";
		} else {
			str += node.right.data;
		}

		System.out.println(str);

		display(node.left);
		display(node.right);
	}

	public int size() {
		return this.size;
	}

	public int size2() {
		return size2(this.root);
	}

	private int size2(Node node) {

		if (node == null)
			return 0;

		int ls = size2(node.left);
		int rs = size2(node.right);

		return ls + rs + 1;
	}

	public int max() {
		return max(this.root);
	}

	private int max(Node node) {

		if (node.right == null) {
			return node.data;
		} else {
			return max(node.right);
		}

	}

	public int height() {
		return height(this.root);
	}

	private int height(Node node) {

		if (node == null)
			return -1;

		int lh = height(node.left);
		int rh = height(node.right);

		return Math.max(lh, rh) + 1;
	}

	public boolean find(int item) {
		return find(this.root, item);
	}

	private boolean find(Node node, int item) {

		if (node == null)
			return false;

		if (item == node.data) {
			return true;
		} else if (item < node.data) {
			return find(node.left, item);
		} else {
			return find(node.right, item);
		}
	}

	public void printInRange(int lower, int upper) {

		printInRange(this.root, lower, upper);
	}

	private void printInRange(Node node, int lower, int upper) {

		if (node == null) {
			return;
		}

		if (node.data >= lower && node.data <= upper) {
			printInRange(node.left, lower, upper);
			System.out.println(node.data);
			printInRange(node.right, lower, upper);
		} else if (node.data > upper) {
			printInRange(node.left, lower, upper);
		} else {
			printInRange(node.right, lower, upper);
		}
	}

	public void printDec() {
		printDec(this.root);
	}

	private void printDec(Node node) {

		if (node == null)
			return;

		printDec(node.right);
		System.out.println(node.data);
		printDec(node.left);
	}

	private class HeapMover {
		int sum;
	}

	public void replaceWithSumOfLarger() {
		HeapMover hm = new HeapMover();
		replaceWithSumOfLarger(this.root, hm);
	}

	private void replaceWithSumOfLarger(Node node, HeapMover hm) {

		if (node == null)
			return;

		replaceWithSumOfLarger(node.right, hm);

		int val = node.data;
		node.data = hm.sum;
		hm.sum += val;

		replaceWithSumOfLarger(node.left, hm);

	}

	public void add(int item) {
		add(this.root, null, false, item);
	}

	private void add(Node node, Node parent, boolean ilc, int item) {

		if (node == null) {
			Node nn = new Node();
			this.size++;
			nn.data = item;

			if (ilc)
				parent.left = nn;
			else
				parent.right = nn;

			return;
		}

		if (item < node.data) {
			add(node.left, node, true, item);
		} else if (item > node.data) {
			add(node.right, node, false, item);
		}

	}

	public void remove(int item) {
		remove(this.root, null, false, item);
	}

	private void remove(Node node, Node parent, boolean ilc, int item) {

		if (item < node.data) {
			remove(node.left, node, true, item);
		} else if (item > node.data) {
			remove(node.right, node, false, item);
		} else {
			if (node.left == null && node.right == null) {
				if (ilc)
					parent.left = null;
				else
					parent.right = null;
			}

			else if (node.left != null && node.right == null) {
				if (ilc)
					parent.left = node.left;
				else
					parent.right = node.left;
			}

			else if (node.right != null && node.left == null) {
				if (ilc)
					parent.left = node.right;
				else
					parent.right = node.right;
			}

			else {

				int max = max(node.left);
				node.data = max;

				remove(node.left, node, true, max);
			}
		}

	}

	public void test() {

		Node n1 = new Node();
		n1.data = 10;
		Node n2 = new Node();
		n2.data = 20;
		Node n3 = new Node();
		n3.data = 30;
		n1.left = n2;
		n2.left = n3;
		n2 = null;
		System.out.println(n1.left.data);
		System.out.println(n1.left.left.data);
	}
	
	

}
