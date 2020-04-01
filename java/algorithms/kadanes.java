
public class kadanes {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int[] arr = { 4, 5, -12, 3, 6, -2, 5, -20, 1, 2, 8 };
		int n = arr.length;
		int si = 0;
		int simax = 0;
		int ei = 0;
		int eimax = 0;
		int max = arr[0];
		int sum = arr[0];
		for (int i = 1; i < n; i++) {
			if (sum > 0) {
				sum += arr[i];
				ei = i;
			} else {
				sum = arr[i];
				si = i;
				ei = i;
			}
			if (sum > max) {
				max = sum;
				simax = si;
				eimax = ei;
			}

		}
		System.out.println(max);
		System.out.println(simax);
		System.out.println(eimax);
		
	}

}
