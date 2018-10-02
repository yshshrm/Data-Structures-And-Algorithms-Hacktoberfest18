

import java.util.ArrayList;
import java.util.Scanner;

public class GenericTree {
	private class Node {
		int data;
		ArrayList<Node> children;

		Node(int data) {
			this.data = data;
			children = new ArrayList<>();
		}
	}

	Node root;
	int size = 0;

	GenericTree() {
		Scanner s = new Scanner(System.in);
		this.root = takeInput(s, null, 0);
		// TODO Auto-generated constructor stub
	}

	private Node takeInput(Scanner s, Node parent, int ithChild) {
		if (parent == null) {
			System.out.println("Enter data for root node");
		} else {
			System.out.println("\nEnter data for " + ithChild + "thchild of " + parent.data);
		}
		int nodeData = s.nextInt();
		Node node = new Node(nodeData);
		this.size++;
		System.out.println("\nEnter number of children for " + node.data);
		int numChild = s.nextInt();
		for (int i = 0; i < numChild; i++) {
			Node child = this.takeInput(s, node, i);
			node.children.add(child);
		}
		return node;

	}

	public void display() {
		System.out.println("\n------------\nTREE OUTPUT");
		this.display(root);
	}

	private void display(Node node) {
		System.out.print("\n" + node.data + "=>");
		for (int i = 0; i < node.children.size(); i++) {
			System.out.print(node.children.get(i).data + ",");
		}
		System.out.println("END");
		for (int i = 0; i < node.children.size(); i++) {
			display(node.children.get(i));
		}
	}

	public int size2() {
		return this.size2(this.root);
	}

	private int size2(Node node) {
		int t = 0;

		for (int i = 0; i < node.children.size(); i++) {
			int childsize = size2(node.children.get(i));
			t = t + childsize;
		}
		return t + 1;
	}

	public int max() {
		return this.max(root);
	}

	private int max(Node node) {
		int max = node.data;
		for (int i = 0; i < node.children.size(); i++) {
			if (max(node.children.get(i)) > max)
				max = node.children.get(i).data;

		}
		return max;
	}

	public int height() {
		return this.height(root);
	}

	private int height(Node node) {
		int height = -1;
		for (int i = 0; i < node.children.size(); i++) {
			int heightofchild = this.height(node.children.get(i));
			if (heightofchild > height)
				height = heightofchild;
		}
		return height + 1;
	}

	public boolean find(int data) {
		return this.find(root, data);
	}

	private boolean find(Node node, int find) {
		boolean flag = false;
		for (int i = 0; i < node.children.size(); i++)
			if (node.children.get(i).data == find) {
				flag = true;
				return flag;
			}
		for (int i = 0; i < node.children.size(); i++) {
			return find(node.children.get(i), find);
		}
		return flag;
	}

	public void mirror() {
		this.mirror(root);
	}

	private void mirror(Node node) {
		int left = 0, right = node.children.size() - 1;
		while (left <= right) {
			Node temp = node.children.get(left);
			node.children.set(left, node.children.get(right));
			node.children.set(right, temp);
			left++;
			right--;
		}
		for (int i = 0; i < node.children.size(); i++)
			this.mirror(node.children.get(i));
	}

	public void printLevel(int level) {
		this.printAtLevel(root, level);
	}

	private void printAtLevel(Node node, int level) {
		if (level == 0) {
			System.out.println(node.data);
			return;
		}
		for (int i = 0; i < node.children.size(); i++) {
			this.printAtLevel(node.children.get(i), level - 1);
		}

	}

	public void preOrder() {
		System.out.println(root.data);
		this.preOrder(root);
	}

	private void preOrder(Node node) {

		for (int i = 0; i < node.children.size(); i++) {
			System.out.println(node.children.get(i).data);
			preOrder(node.children.get(i));

		}

	}

	public void postOrder() {
		this.postOrder(root);
	}

	private void postOrder(Node node) {
		for (int i = 0; i < node.children.size(); i++) {

			preOrder(node.children.get(i));
			System.out.println(node.children.get(i).data);

		}
		System.out.println(root.data);

	}

	public void levelOrder() {
		this.levelOrder(root);
	}

	private void levelOrder(Node node) {

	}
}

//CLIENT
public class GenericTreeClient {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		// 18 3 64 2 17 0 10 0 27 0 39 1 34 0
		GenericTree tree=new GenericTree();
		Scanner s=new Scanner(System.in);
		tree.display();
		System.out.println("\nSize= "+tree.size2());
		System.out.println("\nMax= "+tree.max());
		System.out.println("\nHeight= "+tree.height());
		System.out.println("Enter a number to find: " );
		int find=s.nextInt();
		System.out.println("\nIf "+find+" is present: "+tree.find(find));
		System.out.println("\n-----------Mirror");
		tree.mirror();
		tree.display();
		tree.mirror();
		System.out.println("\n-----------Print At Level 2");
		tree.printLevel(2);
		System.out.println("\n-----------Pre Order Display");
		tree.preOrder();
		System.out.println("\n-----------Post Order Display");
		tree.postOrder();
	}

}

