
import java.io.*;
import java.math.*;
import java.util.*;

public class NonSharedSubstring implements Runnable {
	static String text;

	static class Range {
		int x, y;

		Range(int x, int y) {
			this.x = x;
			this.y = y;
		}

		int length() {
			return Math.abs(x - y);
		}

		char charAt(int i) {
			return text.charAt(x + i);
		}

		@Override
		public boolean equals(Object obj) {
			if (obj == null) {
				return false;
			}

			if (!Range.class.isAssignableFrom(obj.getClass())) {
				return false;
			}

			final Range other = (Range) obj;
			return x == other.x && y == other.y;
		}

	}

	static Range unique = new Range(0, 1000000);
	static TrieTree minLeaf = null;
	static int minLength = Integer.MAX_VALUE;

	static class TrieTree {
		int val;
		boolean left;
		Range range;
		HashMap<Range, TrieTree> children;
		TrieTree parent;

		public TrieTree() {
			parent = null;
			children = new HashMap<Range, TrieTree>();

			left = false;
		}

		public boolean markLeaves() {
			if (children.size() == 0 ) {
				return left = range.x <= hashIndex&&range.y>=hashIndex;
			} else {
				boolean leaves = true;
				for (Map.Entry<Range, TrieTree> entry : children.entrySet()) {

					if (!entry.getValue().markLeaves())
						leaves = false;
				}
				if (leaves)
					return left = true;
				return false;
			}
		}

		public void insert(Range txt) {

			for (Map.Entry<Range, TrieTree> entry : children.entrySet()) {
				Range txt2 = entry.getKey();
				TrieTree tree = entry.getValue();
				if (txt2.length() > 0 && txt.length() > 0 && txt2.charAt(0) == txt.charAt(0)) {
					int i = 1;
					for (; i < txt.length() && i < txt2.length(); i++) {
						if (txt2.charAt(i) != txt.charAt(i))
							break;
					}
					if (i == txt2.length()) {
						tree.insert(new Range(txt.x + i, txt.y));
						return;
					}
					children.remove(txt2);
					Range r = new Range(txt2.x, txt2.x + i);
					TrieTree temp = new TrieTree();
					temp.parent = tree.parent;
					temp.range = r;
					children.put(r, temp);
					if (!children.containsKey(r))
						System.out.println("NULLLLLLL");
					tree.parent = temp;
					Range range3 = new Range(txt2.x + i, txt2.y);
					tree.range = range3;
					children.get(r).children.put(range3, tree);
					TrieTree temp2 = new TrieTree();
					temp2.parent = temp;
					Range range2 = new Range(txt.x + i, txt.y);
					temp2.range = range2;
					children.get(r).children.put(range2, temp2);

					return;
				}
			}
			TrieTree temp = new TrieTree();
			temp.parent = this;
			temp.range = txt;
			children.put(txt, temp);

		}

		public int getStart(TrieTree tree) {
			while (tree.parent.parent != null) {
				return getStart(tree.parent);
			}
			return tree.range.x;
		}

		public int totalLength(TrieTree tree) {
			if (tree.parent == null)
				return 0;
			if (tree.parent.parent == null) {
					return range.length();
			}
			if(!tree.parent.left)
				return range.length() + totalLength(tree.parent);
			else
				return totalLength(tree.parent);
		}

		
		public int printMinLeafLength(TrieTree minLeaf) {
			if(minLeaf.parent==null)
				return Integer.MAX_VALUE;
			if (minLeaf.children.size() == 0 && !minLeaf.parent.left) {

				return 1 + printMinLeafLength(minLeaf.parent);
			} else if (minLeaf.parent!=null&&!minLeaf.parent.left )
				return minLeaf.range.length() + printMinLeafLength(minLeaf.parent);
			else if (minLeaf.parent.parent != null)
				return printMinLeafLength(minLeaf.parent);
			return 0;
		}

		public void display() {
			for (Map.Entry<Range, TrieTree> entry : children.entrySet()) {
				if (entry.getValue().children.size() == 0) {


					if (entry.getKey().x < hashIndex && entry.getKey().y > hashIndex) {
						int totalLength=printMinLeafLength(entry.getValue());
							
						if (totalLength < minLength) {
							minLength = totalLength;
							minLeaf = entry.getValue();
						}

					}

				}

				entry.getValue().display();

			}

		}

		public void printMinLeaf(TrieTree minLeaf) {
			if (minLeaf.parent.parent != null )

				printMinLeaf(minLeaf.parent);

			if (minLeaf.children.size() == 0&&!minLeaf.parent.left) {

				System.out.print(text.charAt(minLeaf.range.x) );
			} else if (!minLeaf.parent.left)
				System.out.print(text.substring(minLeaf.range.x, minLeaf.range.y) );

		}

	}

	static int hashIndex;

	String solve(String p, String q) {
		hashIndex = p.length();
		text = p + "#" + q + "$";
		TrieTree tree = new TrieTree();

		for (int i = 0; i < text.length(); i++) {
			tree.insert(new Range(i, text.length()));
		}
		tree.markLeaves();
		
		tree.display();
		tree.printMinLeaf(minLeaf);
		String result = p;
		return result;
	}

	public void run() {

		try {
			BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
			String p = in.readLine();
			String q = in.readLine();

			String ans = solve(p, q);

			System.out.println (ans);
		} catch (Throwable e) {
			e.printStackTrace();
			System.exit(1);
		}
	}

	public static void main(String[] args) {


        new Thread(new NonSharedSubstring()).start();
	}
}
