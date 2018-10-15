import java.util.Scanner;
import java.util.Random;

class Longest_increasing_subsequence{

public static void main (String [] args) {
		Scanner s = new Scanner(System.in);
		Random r = new Random();
		int N;
		
		do {			
			System.out.print("Enter number of Invitations:\t");
			N = s.nextInt();
		} while (N<1);

		int [] arr = new int[N];

		for (int i=0; i<N; i++) {
			arr[i] = r.nextInt(N)+1;
		}
		
		System.out.print("Random Invitation Numbers  :\t");
		for (int i=0; i<N; i++) {
			System.out.print(arr[i] + " ");
		}
		System.out.println("");
		
		Longest_increasing_subsequence l = new Lis();
		l.lis(arr);
		
	}
	
	public void lis (int [] arr) {
		int [] lisLength = new int[arr.length];		//	stores length of longest increasing subsequence
		int [] lisList = new int[arr.length];		//	keep track of longest increasing subsequence elements
		int max = 1;								//	maXimum length of LIS
		int maxIndex = 0;							//	maXimum length's index of lisList array
		String lisPrint = "";						//	stores final output
		
		for (int i=0; i<arr.length; i++) {
			lisLength[i] = 1;						//	initialize the lisLength array	(by setting 1)
			lisList[i] = -1;						//	initialize the lisList array	(by setting NIL)
			
			for (int j=0; j<i; j++) {
				if (arr[j] < arr[i] && lisLength[i] <= lisLength[j] + 1) {
					lisLength[i] = lisLength[j] + 1;						//	increase LIS length
					lisList[i] = j;											//	stores the index of corresponding LIS
					if (max <= lisLength[i]) {
						max = lisLength[i];									//	update the maX
						maxIndex = i;
					}
				}
			}
		}
		
		for (int i=maxIndex; i>-1;) {
			lisPrint = arr[i] + " " + lisPrint;			//	generate the output String from lisList array
			i = lisList[i];
		}
		
		System.out.println("increasing sequence Length :\t" + max);
		System.out.println("increasing sequence\t   :\t" + lisPrint);
}

}
