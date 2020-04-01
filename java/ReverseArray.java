import java.util.Arrays;
import java.util.Collections;
import java.util.List;


public class ReverseArray {
	
	public static Array[] reverseAnArray(Array numbers) {
		List<Integer> list = Arrays.asList(numbers);
        if(!list.isEmpty()){
        	return Collections.reverse(list);
        }
    }
}
