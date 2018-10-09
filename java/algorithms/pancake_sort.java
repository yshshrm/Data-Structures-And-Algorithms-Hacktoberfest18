public class pancake_sort {

    public static void sort(List<Integer> numbers) {

        for(int currentSize = numbers.size(); currentSize > 1; currentSize--) {
            int largestIndex = findMaxNum(numbers, currentSize);

            if(largestIndex != currentSize-1) {
                flip(numbers, largestIndex);
                flip(numbers, currentSize-1);
            }

        }
        print(numbers);
    }

    private static void flip(List<Integer> numbers, int end) {
        int temp, start = 0;
        while (start < end)
        {
            temp = numbers.get(start);
            numbers.set(start, numbers.get(end));
            numbers.set(end, temp);
            start++;
            end--;
        }
    }

    private static int findMaxNum(List<Integer> numbers, int index) {
        int largestIndex = 0;
        int largest = 0;
        for(int m = 0; m < index; m++) {
            if(numbers.get(m) > largest) {
                largest = numbers.get(m);
                largestIndex = m;
            }
        }
        return largestIndex;
    }

    private static void print(List<Integer> numbers) {
        for(int num: numbers) {
            System.out.println(num);
        }
    }
}