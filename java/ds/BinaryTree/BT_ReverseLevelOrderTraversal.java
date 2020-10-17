package Git;

import java.util.LinkedList;
import java.util.Scanner;

public class BT_ReverseLevelOrderTraversal {

	static Scanner scn = new Scanner(System.in);

	public static void main(String[] args) {

		BT_ReverseLevelOrderTraversal bts = new BT_ReverseLevelOrderTraversal();
		BinaryTree bt = bts.new BinaryTree();
		// 10 true 20 true 40 false false true 50 false false true 30 true 60 false
		// false false **Give this Input to create the tree**

		bt.ReverseLevelOrderTraversal();

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

		public void ReverseLevelOrderTraversal() {
			ReverseLevelOrderTraversal(this.root);
		}

		private void ReverseLevelOrderTraversal(Node node) { // Using a queue & stack

			LinkedList<Node> queue = new LinkedList<>();
			LinkedList<Node> stack = new LinkedList<>();

			queue.addLast(node);

			while (!queue.isEmpty()) {

				Node rn = queue.removeFirst();
				stack.addFirst(rn);

				if (rn.right != null) {
					queue.addLast(rn.right);
				}
				if (rn.left != null) {
					queue.addLast(rn.left);
				}

			}

			while (!stack.isEmpty()) {
				System.out.print(stack.removeFirst().data + " ");
			}

		}

	}
}