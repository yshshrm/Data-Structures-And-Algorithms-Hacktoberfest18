public class kmp {

  public static void main(String[] args) {
    String search = "abacadabrabracabracadabrabrabracad";
    String target = "rabrabra";
    int result = kmp(search, target);
    System.out.println((result == -1) ? "No Match" : "Match");
  }

  public static int kmp(String search, String target) {
    int[] failureTable = failureTable(target);

    int targetPointer = 0; // current char in target string
    int searchPointer = 0; // current char in search string

    while (searchPointer < search.length()) { // while there is more to search with, keep searching
      if (search.charAt(searchPointer) == target.charAt(targetPointer)) {
        // found current char in targetPointer in search string
        targetPointer++;
        if (targetPointer == target.length()) { // found all characters
          int x = target.length() + 1;
          return searchPointer - x; // return starting index of found target inside searched string
        }
        searchPointer++; // move forward if not found target string
      } else if (targetPointer > 0) {
        // use failureTable to use pointer pointed at nearest location of usable string prefix
        targetPointer = failureTable[targetPointer];
      } else {
        // targetPointer is pointing at state 0, so restart search with current searchPointer index
        searchPointer++;
      }
    }
    return -1;
  }

  public static int[] failureTable(String target) {
    int[] table = new int[target.length() + 1];

    table[0] = -1;
    table[1] = 0;

    int left = 0;
    int right = 2;

    while (right < table.length) {
      if (target.charAt(right - 1) == target.charAt(left)) { // when both chars before left and right are equal, link both and move both forward
        left++;
        table[right] = left;
        right++;
      }  else if (left > 0) { // if left isn't at the very beginning, then send left backward
                              // by following the already set pointer to where it is pointing to
        left = table[left];
      } else { // left has fallen all the way back to the beginning
          table[right] = left;
          right++;
      }
    }
    return table;
  }
}