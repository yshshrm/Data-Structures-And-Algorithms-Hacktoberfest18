package Git;

import java.util.Scanner;

public class BT_DiaPair {

	static Scanner scn = new Scanner(System.in);

	public static void main(String[] args) {

		BT_DiaPair bts = new BT_DiaPair();
		BinaryTree bt = bts.new BinaryTree();
		// 10 true 20 true 40 false false true 50 false false true 30 true 60 false
		// false false **Give this Input to create the tree**

		System.out.println(bt.DiaPair());

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

		private int height(Node node) {

			if (node == null) {
				return -1;
			}

			int lh = height(node.left);
			int rh = height(node.right);

			return Math.max(lh, rh) + 1;

		}

		private int diameter(Node node) {

			if (node == null) {
				return 0;
			}

			int ld = diameter(node.left);
			int rd = diameter(node.right);

			int sp = height(node.left) + height(node.right) + 2;

			return Math.max(sp, Math.max(ld, rd));

		}

		private class Pair {
			int height = -1;
			int diameter = 0;
		}

		public int DiaPair() {
			Pair pair = DiaPair(this.root);
			return pair.diameter;
		}

		private Pair DiaPair(Node node) {

			if (node == null) {
				Pair br = new Pair();
				return br;
			}

			Pair lr = DiaPair(node.left);
			Pair rr = DiaPair(node.right);

			Pair mr = new Pair();
			mr.height = Math.max(lr.height, rr.height) + 1;

			int ld = diameter(node.left);
			int rd = diameter(node.right);
			int sp = lr.height + rr.height + 2;

			mr.diameter = Math.max(sp, Math.max(ld, rd));

			return mr;

		}

	}
}