public class SelectionSort<E> {

    public <E extends Comparable<E>> void selectionSort(E[] arr){
        int i, j;
        int min;
        E tmp;

        if(arr.length == 0) return;

        for(i = 0; i < arr.length-1; i++){
            min = i; //suppose that the first number of our subarray is the smallest
            for(j = i+1; j < arr.length; j++){
                if(arr[j].compareTo(arr[min]) < 0) min = j; //if I find a smaller number I update the variable min
            }
            if(arr[min].compareTo(arr[i]) != 0){//if a swap is needed...
                tmp = arr[min];                 //i swap the position of the first number of the subarray...
                arr[min] = arr[i];             //with the smallest number of the subarray
                arr[i] = tmp;
            }
        }
        return;
    }
}
