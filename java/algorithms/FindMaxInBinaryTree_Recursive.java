public class FindMaxInBinaryTree_Recursive(){
		public static int max(LinkedBinaryTree<Integer> T) {
		if(!T.isEmpty())
			return maxAux(T,T.root);
		return 0;
	}
	
	private static int maxAux(LinkedBinaryTree<Integer> T,Position<Integer> localroot) {
		int answer = localroot.getElement();
		if(T.left(localroot) != null) {
			int m1 = maxAux(T,T.left(localroot));
			if(m1>answer)
				answer = m1;
		}
		if(T.right(localroot) != null) {
			int m2 = maxAux(T,T.right(localroot));
			if(m2>answer)
				answer = m2;
		}
		
		return answer;	
		
	}
}