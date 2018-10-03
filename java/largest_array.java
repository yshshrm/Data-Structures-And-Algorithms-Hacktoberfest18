import java.util.stream.IntStream;


public class largest_array {

	public Array largestArray(int[] a, int[] b){
		int sumOfA = IntStream.of(a).sum();
		int sumOfB = IntStream.of(b).sum();
		if(sumOfA > sumOfB){
			System.out.print("The first array is bigger than the second array with a total of: "+ sumOfA);
		} else {
			System.out.print("The second array is bigger than the first array with a total of: " + sumOfB);
		}
		
	}
	
}
