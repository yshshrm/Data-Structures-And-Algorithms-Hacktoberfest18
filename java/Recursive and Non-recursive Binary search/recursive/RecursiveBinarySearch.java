import java.util.Scanner;

public class RecursiveBinarySearch {
    public static void main(String args[]){
        //integer array
        int[] intArray={5,10,15,20,25,30,35,45,50,55};
        System.out.println("\t\t\t|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|");
        System.out.println("\t\t\t|                 RECURSIVE BINARY SEARCH                 |");
        System.out.println("\t\t\t|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");
        //create scanner
        Scanner searchValue = new Scanner(System.in);
        System.out.print("Enter search value ->");
        //store input value into inputVal integer
        int inputVal = searchValue.nextInt();
        System.out.println("\t\t\t|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|");
        //call method RecursiveSearch() and store return value into int searchResult
        //pass 0 for firstIndex parameter.
        //pass -1 from intArray length for finalIndex parameter.
        //pass input value for searchValue parameter.
        //pass intArray for int[] Array parameter.
        int searchResult = RecursiveSearch(0,intArray.length - 1, inputVal , intArray );
        long startTime = System.nanoTime();
        //if the return value equals to -1 display 0 result for search value
        //else display position of search value.
        if(searchResult == -1){
            System.out.println  ("\t\t\t|0 result for search value\n");
        }else {
            System.out.println  ("\t\t\t|Search result for "+inputVal+" found at position -> "+ (searchResult + 1) +" and Array index -> "+ searchResult);
            long endTime = System.nanoTime();
            System.out.println("\t\t\t|Time take for recursive structure ->> " + (endTime - startTime));
        }
        System.out.println("\t\t\t|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");
        System.out.print("Search again ? (Y)es or (N)o ->");
        String gainType = searchValue.next();
        if(gainType.equals("Y") || gainType.equals("y")){
            main(args);
        }else {
            System.exit(1);
        }
    }

    public static int RecursiveSearch(int lowerlimit,int upperlimit, int searchValue, int[] Array){
        //return -1 if lowerlimit > finalindex
        if(lowerlimit > upperlimit){
            return -1;
        }else {
            //get middle
            int middle = (lowerlimit + upperlimit)/2;
            //check middle is equals to search value if equals return middle
            if(searchValue == Array[middle]){

                return middle;
                //check else if search value is < to middle index of array
            }else if(searchValue < Array[middle]){
                //returm RecursiveSearch method and middle -1 as finalindex
                return RecursiveSearch(lowerlimit,middle-1, searchValue, Array);
            }else {
                //else return RecursiveSearch method and middle +1 as lowerlimit
                return RecursiveSearch(middle+1,upperlimit, searchValue,Array);
            }
        }
    }
}