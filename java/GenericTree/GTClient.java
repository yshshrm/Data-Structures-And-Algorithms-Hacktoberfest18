package L17_March3;


public class GTClient {

	public static void main(String[] args) {

		// 10 3 20 2 50 0 60 0 30 0 40 1 55 0
		// 10 3 20 3 50 0 60 0 70 0 30 2 120 0 130 0 40 4 80 0 90 0 100 0 110 0
		// 10 3 20 2 50 0 60 2 100 0 110 2 180 0 190 0 30 0 40 3 70 2 120 0 140 0 80 1
		// 150 1 200 0 90 2 160 0 170 0
		GenericTree tree = new GenericTree();
		tree.display();

		// System.out.println(tree.find(60));
		// System.out.println(tree.height());
		// System.out.println(tree.size2());
		// System.out.println(tree.max());

		// tree.mirror();
		// tree.display();

		tree.preorder();
		// tree.postorder();

		// tree.traversal();

		// tree.levelorder();
		// tree.levelorderLW();
		// tree.levelorderZZ();

		// tree.multiSolver(35);
		tree.preorderI();
	}

}
