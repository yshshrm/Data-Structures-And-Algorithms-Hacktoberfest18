public class SelectionSort<E> {

    public <E extends Comparable<E>> void selectionSort(E[] arr){
        int i, j;
        int min;
        E tmp;

        if(arr.length == 0) return;

        for(i = 0; i < arr.length-1; i++){
            min = i;
            for(j = i+1; j < arr.length; j++){
                if(arr[j].compareTo(arr[min]) < 0) min = j;
            }
            if(arr[min].compareTo(arr[i]) != 0){
                tmp = arr[min];
                arr[min] = arr[i];
                arr[i] = tmp;
            }
        }
        return;
    }
}
