import java.io.*;
public class CyclicRotationArray {
	
	public void Rotate(int arr[]) {
		
		int x= arr[arr.length-1];
		
		for(int i=arr.length-1; i>0;i--) {
			
			arr[i]=arr[i-1];
		}
		arr[0]=x;
	}
	
	public void printarray(int arr[]) {
		
		for(int i=0;i<arr.length;i++) {
			
			System.out.print(arr[i]+" ");
		}
	}
	
	public static void main(String args[]) {
		
		CyclicRotation rotate=new CyclicRotation();
		int[] arr= {1,2,3,4,5,6};
		
		rotate.Rotate(arr);
		rotate.printarray(arr);
	}

}
