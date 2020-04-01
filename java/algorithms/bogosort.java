import java.util.Random;
public class bogosort{
  public static void main(String[] args) {
    int[] values = {3,8,4,7,5,1,9,2,6};
    bogosort(values);
  }
  private static void bogosort(int[] values) {
    Random r = new Random();
    int count = 1;
    while(!isSorted(values)) {
      for(int x = 0; x < values.length; x++)
        values = switchSpots(values, x, r.nextInt(values.length));
      System.out.print(count++ + ": ");printAll(values);
    }
  }
  private static boolean isSorted(int[] values) {
    for(int x = 0; x < values.length-1; x++)
    if(values[x] > values[x+1]) return false;
    return true;
  }
  private static void printAll(int[] values) {
    for(int i:values)
      System.out.print(i + " ");
    System.out.println();
  }
  private static int[] switchSpots(int[] values, int index1, int index2){
    int temp = values[index1];
    values[index1] = values[index2];
    values[index2] = temp;
    return values;
  }

}
