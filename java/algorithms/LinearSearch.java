import java.util.Scanner;

public class LinearSearch {

	public static void main(String[] args) {
		
		Scanner sc;
		int size;
		int[] arr;
		int val;
		
		sc = new Scanner(System.in);
		
		System.out.print("Enter size of your array:");
		size= sc.nextInt();
		arr= new int[size];
		
		System.out.println("enter values for position:");
		for(int i=0;i<size;i++) {
			System.out.print(""+i+":");
			arr[i]=sc.nextInt();
		}
		
		System.out.print("enter value to be searched:");
		val= sc.nextInt();
		
		int result= linSearch(arr,val);
		if(result==-1) {
			System.out.println("values not found");
		}
		else {
			System.out.println("value found at position:"+result);
		}
		
		sc.close();
	}

	private static int linSearch(int[] arr, int val) {
		for (int i=0;i<arr.length;i++) {
			if(arr[i]==val) {
				return i;
			}
		}
		
		return -1;
	}

}
