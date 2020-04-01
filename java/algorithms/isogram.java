import java.io.*;
import java.util.*;

public class isogram {
  public static void main ( String [] argv ) {
    System.out.println(checkIsogram("charcter"));
  }

  public static String checkIsogram( String word ) {
    word = word.toLowerCase(); // convert to lowercase
    int len = word.length(); // get world length

    char arr_word[] = word.toCharArray(); // convert string to array characters
    Arrays.sort(arr_word); // sort array

    String res;

    for(int i = 0; i < len-1; i++) {
      if(arr_word[i] == arr_word[ i+1 ]) {
        res = word+" is not an isogram, "+ arr_word[i] +" repeats";
        return res;
      }
    }
    return word+" is an isogram";
  }
}