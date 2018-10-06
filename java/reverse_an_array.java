import java.util.Arrays;
import java.util.Collections;
import java.util.List;


public class reverse_an_array {
	
	public static List<Integer> reverseAnArray(List<Integer> list) {
		if(!list.isEmpty()){
			Collections.reverse(list);
		}
		return list;
	}
}
