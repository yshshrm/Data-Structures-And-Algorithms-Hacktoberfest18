/**
 * Date: 2018-10-01
 */

public class CountingSort {
	public static char[] sort(char[] input, boolean replaceInput) 
	{
		char[] sorted = sort(input);
		
		if( replaceInput ) {
			// Copy the output array to input array
	        for (int i = 0; i < sorted.length; i++) 
	            input[i] = sorted[i]; 
		}
		
		return sorted;
	}
	
	public static char[] sort(char[] input) 
    { 
	    // Create output array with size of input 
        char output[] = new char[input.length]; 
  
        // Create array to hold occurences of each
        // character (char = 256)
        int countForChar[] = new int[256]; 
        
        // Initialize to 0 (java defaults to zero but better to be safe)
        for (int i=0; i<256; ++i) 
        	countForChar[i] = 0; 
  
        // Loop trough all characters in inputstore count of each character 
        for (int i = 0; i < input.length; i++) 
            countForChar[input[i]]++; 
  
        int outputPos = 0;
        for( int i = 1; i <= 255; i++ ) {
        	if( countForChar[i] > 0 ) {
        		for( int j = 0; j < countForChar[i]; j++) {
        			output[outputPos] = (char)i;
        			outputPos++;
        		}
        	}
        }
        
        return output;
    } 
}
