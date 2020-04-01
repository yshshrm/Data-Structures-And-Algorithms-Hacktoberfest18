public class LargestNumber
{
  public static void main(String[] args)
  {
    int[] numbers={1,2,3,4,5,6,7,342,4324,1,13,3423,5454,534,14765,87,746,7,13298}; //Random set of selected integers
    int largest=0;
    
    for(int x=0;x<=numbers.length-1;x++) //start at the first value of the set, and move up one value at a time
    {
      if(numbers[x]>largest)
        largest=numbers[x];
    }
    System.out.println("The largest number in the set is "+largest);
  }
}