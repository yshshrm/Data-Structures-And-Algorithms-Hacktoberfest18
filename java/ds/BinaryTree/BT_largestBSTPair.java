package Git;

import java.util.Scanner;

public class BT_largestBSTPair {

	static Scanner scn = new Scanner(System.in);

	public static void main(String[] args) {

		BT_largestBSTPair bts = new BT_largestBSTPair();
		BinaryTree bt = bts.new BinaryTree();
		// 10 true 20 true 40 false false true 50 false false true 30 true 60 false
		// false false **Give this Input to create the tree**

		bt.largestBST();

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

		private class BSTPair {

			int max = Integer.MIN_VALUE;
			int min = Integer.MAX_VALUE;
			boolean isBST = true;
			Node largestBSTNode = null;
			int size = 0;

		}

		public void largestBST() {
			BSTPair bst = new BSTPair();
			bst = largestBST(this.root);
			System.out.println(bst.largestBSTNode.data);
			System.out.println(bst.size);
			System.out.println(bst.max);
			System.out.println(bst.min);
		}

		private BSTPair largestBST(Node node) {

			if (node == null) {
				BSTPair pair = new BSTPair();
				return pair;
			}

			BSTPair left = largestBST(node.left);
			BSTPair right = largestBST(node.right);

			BSTPair mr = new BSTPair();
			mr.max = Math.max(node.data, Math.max(left.max, right.max));
			mr.min = Math.min(node.data, Math.min(left.min, right.min));

			if (left.isBST && right.isBST && node.data > left.max && node.data < right.min) {
				mr.isBST = true;
				mr.largestBSTNode = node;
				mr.size = left.size + right.size + 1;
			} else {
				mr.isBST = false;
				if (left.size > right.size) {
					mr.largestBSTNode = left.largestBSTNode;
					mr.size = left.size;
				} else {
					mr.largestBSTNode = right.largestBSTNode;
					mr.size = right.size;
				}

			}

			return mr;

		}

	}
}