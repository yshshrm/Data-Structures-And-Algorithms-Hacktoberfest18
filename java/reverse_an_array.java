import java.util.Arrays;
import java.util.Collections;
import java.util.List;


public class reverse_an_array {
	
	public static Array[] reverseAnArray(Array numbers) {
		List<Integer> list = Arrays.asList(numbers);
        if(!list.isEmpty()){
        	return Collections.reverse(list);
        }
    }
}
