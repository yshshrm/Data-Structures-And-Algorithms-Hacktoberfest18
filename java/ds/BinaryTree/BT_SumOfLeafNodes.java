package Git;

import java.util.Scanner;

public class BT_SumOfLeafNodes {

	static Scanner scn = new Scanner(System.in);

	public static void main(String[] args) {

		BT_SumOfLeafNodes bts = new BT_SumOfLeafNodes();
		BinaryTree bt = bts.new BinaryTree();
		// 10 true 20 true 40 false false true 50 false false true 30 true 60 false
		// false false **Give this Input to create the tree**

		System.out.println(bt.SumofLeafNodes());

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

		private class Res {// For Calculating Sum of Leaf Nodes
			int sum = 0;
		}

		public int SumofLeafNodes() {
			Res r = new Res();
			leafSum(this.root, r);
			return r.sum;
		}

		private void leafSum(Node root, Res r) {
			if (root == null)
				return;

			if (root.left == null && root.right == null)
				r.sum += root.data;

			leafSum(root.left, r);
			leafSum(root.right, r);

		}

	}
}