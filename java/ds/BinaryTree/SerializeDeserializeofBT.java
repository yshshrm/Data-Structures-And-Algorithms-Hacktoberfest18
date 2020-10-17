package Git;

import java.util.Scanner;

public class SerializeDeserializeofBT {

	static Scanner scn = new Scanner(System.in);

	public static void main(String[] args) {

		SerializeDeserializeofBT bts = new SerializeDeserializeofBT();
		BinaryTree bt = bts.new BinaryTree();
		// 10 true 20 true 40 false false true 50 false false true 30 true 60 false
		// false false **Give this Input to create the tree**

		String str = bt.serialize();
		System.out.println(str);
		// # -> represent root node
		bt.root = bt.deserialize(str);
		bt.display(bt.root);

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

		public void inOrderR(Node node) {

			if (node == null) {
				return;
			}

			inOrderR(node.left);
			System.out.print(node.data + " ");
			inOrderR(node.right);

		}

		public String serialize() {
			String s = serialize(this.root);
			Node nn = deserialize(s);
			// System.out.println(nn.data);
			inOrderR(nn);
			System.out.println();
			return s.substring(0, s.length() - 1);
		}

		private String serialize(Node root) {

			if (root == null) {
				return "#,";
			}

			String s = Integer.toString(root.data);
			String la = serialize(root.left);
			String ra = serialize(root.right);

			return s + "," + la + ra;

		}

		public Node deserialize(String data) {
			if (data == null)
				return null;

			int[] t = { 0 };
			String[] arr = data.split(",");

			return helper(arr, t);
		}

		public Node helper(String[] arr, int[] t) {
			if (arr[t[0]].equals("#")) {
				return null;
			}

			Node node = new Node();
			node.data = Integer.parseInt(arr[t[0]]);

			t[0] = t[0] + 1;
			node.left = helper(arr, t);
			t[0] = t[0] + 1;
			node.right = helper(arr, t);

			return node;
		}

	}
}