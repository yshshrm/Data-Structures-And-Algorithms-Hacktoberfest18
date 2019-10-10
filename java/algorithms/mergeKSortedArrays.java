import java.util.PriorityQueue;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;

public class mergeKSortedArrays {
	
	public static ArrayList<Integer> mergeKSortedArrays(ArrayList<ArrayList<Integer>> input) {
		PriorityQueue<Integer> ans = new PriorityQueue<Integer>();
		for(int i=0;i<input.size();i++) {
			for(int j=0;j<input.get(i).size();j++) {
				ans.add(input.get(i).get(j));
			}
		}
		ArrayList<Integer> Ans = new ArrayList<Integer>();
		while(!ans.isEmpty()) {
			Ans.add(ans.remove());
		}
		return Ans;
	}

}
