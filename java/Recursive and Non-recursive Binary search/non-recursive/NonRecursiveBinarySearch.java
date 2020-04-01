import java.util.Scanner;

public class NonRecursiveBinarySearch {
    public static void main(String args[]) {
        //integer array
        int[] intArray = {5, 10, 15, 20, 25, 30, 35, 45, 50, 55};
        System.out.println("\t\t\t|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|");
        System.out.println("\t\t\t|               NON-RECURSIVE BINARY SEARCH               |");
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
        int searchResult = NonRecursiveSearch(inputVal, intArray);
        long startTime = System.nanoTime();
        //if the return value equals to -1 display 0 result for search value
        //else display position of search value.
        if (searchResult == -1) {
            System.out.println("\t\t\t|0 result for search value\n");
        } else {

            System.out.println("\t\t\t|Search result for " + inputVal + " found at position -> " + (searchResult + 1) + " and Array index -> " + searchResult);
            long endTime = System.nanoTime();
            System.out.println("\t\t\t|Time take for Non-recursive structure ->> " + (endTime - startTime));
        }
        System.out.println("\t\t\t|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");
        System.out.print("Search again ? (Y)es or (N)o ->");
        String gainType = searchValue.next();
        if (gainType.equals("Y") || gainType.equals("y")) {
            main(args);
        } else {
            System.exit(1);
        }
    }
    public static int NonRecursiveSearch(int searchValue, int[] Array){
        //assign lowerlimit as 0
        int lowerlimit = 0;
        //assing upperlimit as array length - 1
        int upperlimit = Array.length - 1;
        //do process while lowerlimit less than or equal to upperlimit
        while (lowerlimit <= upperlimit){
            //assign middleIndex as lowerlimit + upperlimt deivide by 2
            int middleIndex = (lowerlimit+upperlimit)/2;
            //assign upperlimit as middleInde - 1 if searchValue less than middle index of array
            if(searchValue < Array[middleIndex]){
                upperlimit = middleIndex - 1;
                //assign lowerlimit as middleInde - 1 if searchValue grater than middle index of array
            }else if(searchValue > Array[middleIndex]){
                lowerlimit = middleIndex + 1;
            }else{
                //else retuen middle index

                return middleIndex;
            }
        }
        //return -1 if search value is not found
        return -1;
    }
}