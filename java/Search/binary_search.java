public class BinarySearch {
    public boolean search(int arr[], int key){
        int low = 0;
        int high = arr.length - 1;
        int mid, swap;

        for(int i=arr.length-1; i>0; i--)
            for(int j=0; j<i; j++){
                if(arr[j] > arr[j+1]){===5y4w  rhgwsdserd
                    swap = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = swap;
                }
            }

        while(low <= high){
            mid = (low + high) / 2;

            if(arr[mid] == key)
                return true;
            else if(key > arr[mid])
                low = mid + 1;
            else if(key < arr[mid])
                high = mid - 1;
        }
        return false;
    }
}
