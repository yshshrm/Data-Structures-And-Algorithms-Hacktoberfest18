import java.util.Arrays;

//pigeonhole sort is similar to counting sort and can be used when number of elements and possible key values are approximately same.
/*
 * Find minimum and maximum values in array. Let the minimum and maximum values be ‘min’ and ‘max’ respectively. Also find range as ‘max-min-1’.
 * Set up an array of initially empty “pigeonholes” the same size as of the range.
 * Visit each element of the array and then put each element in its pigeonhole. An element arr[i] is put in hole at index arr[i] – min.
 * Start the loop all over the pigeonhole array in order and put the elements from non- empty holes back into the original array.
 * */
public class PigeonholeSort {

	static void pigeonHoleSort(int arr[]) {
		
		int min = arr[0]; 
        int max = arr[0]; 
        int range, i, j, index;  
        
        for( i=0;i<arr.length;i++)
        {
        	if(arr[i]>max)
        		max=arr[i];
        	if(arr[i]<min)
        		min=arr[i];
        }
        
        range= max-min+1;
        int[] phole = new int[range]; 
        Arrays.fill(phole, 0);
        
        for(i = 0; i<arr.length; i++) 
            phole[arr[i] - min]++; 
        
        index = 0; 
        
        for(j = 0; j<range; j++) 
            while(phole[j]-->0) 
                arr[index++]=j+min;
        		
	}
	
	public static void main(String...args) {
		int[] arr = {9, 10, 2, 5, 4, 6, 9, 7}; 
		pigeonHoleSort(arr);
		System.out.println("Printing the sorted order");
		for(int i=0;i<arr.length;i++)
		{
			System.out.print(arr[i]+" ");
		}
	}
}
