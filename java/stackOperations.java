import java.util.Scanner;

public class stackOperations{

	public static void reverse(int[] a, int i, int j){
		while(i < j){
			int temp = a[i];
			a[i] = a[j];
			a[j] = temp;
			i++;
			j--;
		}
	}

	public static void leftrotate(int[] a, int x) {
		int n = a.length;
		x = n-(x%n);
		reverse(a, 0, n-1);
		reverse(a, 0, x-1);
		reverse(a, x, n-1);
	}
	
	public static void rightrotate(int[] a, int x) {
		int n = a.length;
		x = x%n;
		reverse(a, 0, n-1);
		reverse(a, 0, x-1);
		reverse(a, x, n-1);
	}

	public static int[] delete(int[]a, int x){
		if (a == null || x < 0  || x >= a.length) { 
            wrong();
		}
		int[] newArr = new int[a.length - 1];
		int j = 0;
    	for(int i = 0; i < a.length; i++) {
        	if(i == x) {
            	continue;
			}
			newArr[j++] = a[i];
		}
		return newArr;
	}

	public static void wrong(){
		System.out.print("-1");
		System.exit(0);
	}
	public static void main(String[] args) {
		int n, o;
	
		Scanner in = new Scanner(System.in);
		Scanner in2 = new Scanner(System.in);
		
		n = in.nextInt();
		
		int a[] = new int[n];
		for(int i = 0; i < n; i++){
			a[i] = in.nextInt();
		}

		o = in.nextInt();
		
		String[] array = new String[o];

		for(int i = 0; i < o; i++){
			array[i] = in2.nextLine();
		}

		for(int i = 0; i < o; i++){
			if(array[i].charAt(0)=='L'){
				int x = Integer.parseInt(array[i].substring(2));
				leftrotate(a, x);
			}
			else if(array[i].charAt(0)=='R'){
				int x = Integer.parseInt(array[i].substring(2));
				rightrotate(a, x);
			}
			else if(array[i].charAt(0)=='D'){
				int x = Integer.parseInt(array[i].substring(2));
				a = delete(a, x);
				n--;
			}
			else{
				wrong();
			}
		}
		if (a.length == 0) {
			wrong();
		}
		else{
			for(int i = 0; i < n; i++){
				System.out.print(a[i]+" ");
			}
		}		
	}// End of main function
}