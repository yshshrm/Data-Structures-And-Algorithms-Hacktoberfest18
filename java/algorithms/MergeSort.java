import java.util.*;

public class MergeSort{

    public int[] array;

    public MergeSort(int[] array){
        this.array = array;
    }

    public void sort(int p, int r){
        int q;
        if (p < r){
            q = (p + r) / 2;
            sort(p, q);
            sort(q + 1, r);
            merge(p, q, r);
        }
    }

    public void merge(int p, int q, int r){
        int j = p;
        int k = q + 1;
        int i = 0;
        int supportArray[] = new int[r - p + 1];

        while(j <= q || k <= r){
            if(j <= q && (k > r || this.array[j] <= this.array[k])){
                supportArray[i] = this.array[j];
                j++;
            }
            else{
                supportArray[i] = this.array[k];
                k++;
            }
            i++;
        }

        for(i = 0; i < (r - p + 1); i++){
            this.array[p + i] = supportArray[i];
        }
    }

    public String toString(){
        String result = "[ ";
        for(int i = 0; i < this.array.length; i++){
            result = result + this.array[i] + "; ";
        }
        return result + "]" ;
    }
    
    public static void main(String args[]){
        int array[] = new int[10];
        Random random = new Random();
        for(int i = 0; i < 10; i++){
            array[i] = random.nextInt(100);
        }
 
        MergeSort orderedArray = new MergeSort(array);
        System.out.println("Array:" + orderedArray.toString());
        orderedArray.sort(0, array.length - 1   );
 
        System.out.println("Sorted Array: " + orderedArray.toString());
    }
}