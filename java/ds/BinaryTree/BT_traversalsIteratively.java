package Git;

import java.util.LinkedList;
import java.util.Scanner;

public class BT_traversalsIteratively {

	static Scanner scn = new Scanner(System.in);

	public static void main(String[] args) {

		BT_traversalsIteratively bts = new BT_traversalsIteratively();
		BinaryTree bt = bts.new BinaryTree();
		// 10 true 20 true 40 false false true 50 false false true 30 true 60 false
		// false false **Give this Input to create the tree**

		bt.inOrderI();
		bt.postOrderI();
		bt.preOrderI();

	}

	private class BinaryTree {

		private class Node {
			int data;
			Node left;
			Node right;
		}

		private Node root;
		private int size;

		public BinaryTree() {
			this.root = construct(null, false);
		}

		private Node construct(Node parent, boolean ilc) {

			if (parent == null) {
				System.out.println("Enter the data for root node ? ");
			} else {
				if (ilc) {
					System.out.println("Enter the data for left " + parent.data);
				} else {
					System.out.println("Enter the data for right " + parent.data);
				}
			}

			int val = scn.nextInt();
			Node nn = new Node();
			nn.data = val;
			this.size++;

			boolean lc;
			System.out.println("Do you want left child");
			lc = scn.nextBoolean();
			if (lc) {
				nn.left = construct(nn, true);
			}

			boolean rc;
			System.out.println("Do you want right child");
			rc = scn.nextBoolean();
			if (rc) {
				nn.right = construct(nn, false);
			}

			return nn;

		}

		public void display() {
			display(this.root);
		}

		private void display(Node node) {

			if (node == null) {
				return;
			}

			String str = "";

			if (node.left != null) {
				str += node.left.data;
			} else {
				str += ".";
			}

			str += "->" + node.data + "<-";

			if (node.right != null) {
				str += node.right.data;
			} else {
				str += ".";
			}
			System.out.println(str);
			display(node.left);
			display(node.right);

		}

		private class OrderPair {

			Node node;
			boolean selfDone;
			boolean leftDone;
			boolean rightDone;

		}

		public void preOrderI() {

			LinkedList<OrderPair> stack = new LinkedList<>();

			OrderPair sp = new OrderPair();
			sp.node = this.root;

			stack.addFirst(sp);

			while (!stack.isEmpty()) {

				OrderPair tp = stack.getFirst();

				if (tp.selfDone == false) {
					System.out.print(tp.node.data + " ");
					tp.selfDone = true;
				} else if (tp.leftDone == false) {
					if (tp.node.left != null) {
						OrderPair np = new OrderPair();
						np.node = tp.node.left;
						stack.addFirst(np);
					}
					tp.leftDone = true;
				} else if (tp.rightDone == false) {
					if (tp.node.right != null) {
						OrderPair np = new OrderPair();
						np.node = tp.node.right;
						stack.addFirst(np);
					}
					tp.rightDone = true;
				} else {
					stack.removeFirst();
				}

			}
			System.out.println();
		}

		public void inOrderI() {

			LinkedList<OrderPair> stack = new LinkedList<>();

			OrderPair sp = new OrderPair();
			sp.node = this.root;

			stack.addFirst(sp);

			while (!stack.isEmpty()) {

				OrderPair tp = stack.getFirst();

				if (tp.leftDone == false) {
					if (tp.node.left != null) {
						OrderPair np = new OrderPair();
						np.node = tp.node.left;
						stack.addFirst(np);
					}
					tp.leftDone = true;
				} else if (tp.selfDone == false) {
					System.out.print(tp.node.data + " ");
					tp.selfDone = true;
				} else if (tp.rightDone == false) {
					if (tp.node.right != null) {
						OrderPair np = new OrderPair();
						np.node = tp.node.right;
						stack.addFirst(np);
					}
					tp.rightDone = true;
				} else {
					stack.removeFirst();
				}

			}
			System.out.println();
		}

		public void postOrderI() {
			LinkedList<OrderPair> stack = new LinkedList<>();

			OrderPair sp = new OrderPair();
			sp.node = this.root;

			stack.addFirst(sp);

			while (!stack.isEmpty()) {

				OrderPair tp = stack.getFirst();

				if (tp.leftDone == false) {
					if (tp.node.left != null) {
						OrderPair np = new OrderPair();
						np.node = tp.node.left;
						stack.addFirst(np);
					}
					tp.leftDone = true;
				} else if (tp.rightDone == false) {
					if (tp.node.right != null) {
						OrderPair np = new OrderPair();
						np.node = tp.node.right;
						stack.addFirst(np);
					}
					tp.rightDone = true;
				} else if (tp.selfDone == false) {
					System.out.print(tp.node.data + " ");
					tp.selfDone = true;
				} else {
					stack.removeFirst();
				}

			}
			System.out.println();
		}

	}
}