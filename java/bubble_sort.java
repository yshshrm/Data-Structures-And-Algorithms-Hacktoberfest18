class bubble_sort() {

    public static int[] sort(int[] array) {
        int arrayEnd = array.length - 1;

        for(int i=0; i<arrayEnd; i++) {
            for(int j=0; j < arrayEnd; j++) {
                if(array[j] > array[j+1]) {
                    int temp = array[j+1];
                    array[j+1] = array[j];
                    array[j] = temp;
                }
            }
        }
        return array;
    }

}