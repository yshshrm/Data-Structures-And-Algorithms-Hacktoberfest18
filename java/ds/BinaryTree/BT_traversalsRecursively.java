package Git;

import java.util.Scanner;

public class BT_traversalsRecursively {

	static Scanner scn = new Scanner(System.in);

	public static void main(String[] args) {

		BT_traversalsRecursively bts = new BT_traversalsRecursively();
		BinaryTree bt = bts.new BinaryTree();
		// 10 true 20 true 40 false false true 50 false false true 30 true 60 false
		// false false **Give this Input to create the tree**

		bt.inOrderR();
		bt.preOrderR();
		bt.postOrderR();

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

		public void preOrderR() {
			preOrderR(this.root);
			System.out.println();
		}

		private void preOrderR(Node node) {

			if (node == null) {
				return;
			}

			System.out.print(node.data + " ");
			preOrderR(node.left);
			preOrderR(node.right);

		}

		public void postOrderR() {
			postOrder(this.root);
			System.out.println();
		}

		private void postOrder(Node node) {

			if (node == null) {
				return;
			}

			postOrder(node.left);
			postOrder(node.right);
			System.out.print(node.data + " ");

		}

		public void inOrderR() {
			inOrderR(this.root);
			System.out.println();
		}

		public void inOrderR(Node node) {

			if (node == null) {
				return;
			}

			inOrderR(node.left);
			System.out.print(node.data + " ");
			inOrderR(node.right);

		}

	}
}