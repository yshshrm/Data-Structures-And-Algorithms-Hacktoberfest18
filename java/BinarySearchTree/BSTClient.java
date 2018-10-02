package L21_March11;

import java.util.ArrayList;



public class BSTClient {

	public static void main(String[] args) {

		int[] in = { 10, 20, 30, 40, 50, 60, 70, 80 };
		BST bst = new BST(in);
		bst.display();

		// bst.printInRange(40, 75);
		// bst.printDec();
		// bst.replaceWithSumOfLarger();
		// bst.display();
		// bst.add(100);
		// bst.add(25);
		bst.remove(70);
		bst.display();
		// ArrayList<ArrayList<Integer>> list = new ArrayList<>();
		// list.add(new ArrayList<>()) ;
		// list.add(new ArrayList<>()) ;
		// list.get(0).add(10) ;
		// list.get(1).add(10) ;
		//
		//
		// System.out.println(list);

		// bst.test();
	}

}
