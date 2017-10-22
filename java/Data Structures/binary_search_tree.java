class Node {
	Node left;
	Node right;
	int value;
	
	Node(int value){
		this.value = value;
	}
}

public void search(Node node, int key) {
	if (node.value == key || n == null) {
		System.out.println("Value is found");
	} else if (key < node.value) {
		search(n.left, key);
	} else {
		search(n.right, key);
	}
} 