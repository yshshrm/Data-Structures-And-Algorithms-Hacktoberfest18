import javafx.util.Pair;

public class PriorityQueue<T> {
    int size, upperBound;
    Nodep[] pqArray;
    PriorityQueue(){
        this.size = 0;
        this.upperBound = 0;
        this.pqArray = new Nodep[this.size];
    }

    private void heapify(int i){
        int parent;
        if(i%2 == 1)
            parent = (i-1)/2;
        else
            parent = (i-2)/2;
        if(this.pqArray[parent].pRank > this.pqArray[i].pRank){
            Nodep temp = this.pqArray[parent];
            this.pqArray[parent] = this.pqArray[i];
            this.pqArray[i] = temp;
            if(parent != 0)
                this.heapify(parent);
        }
    }

    public void insert(int pRank,T element){
        if(this.upperBound == this.size) {
            Nodep[] duparr = new Nodep[this.size];
            for (int i = 0; i < this.size; i++) {
                duparr[i] = this.pqArray[i];
            }
            this.pqArray = new Nodep[++this.size];
            this.upperBound++;
            if(this.size != 1){
                for(int i=0;i<this.size-1;i++) {
                    this.pqArray[i] = duparr[i];
                }
            }
        }else{
            this.size++;
        }
        this.pqArray[this.size-1] = new Nodep(pRank, element);
        if(this.size != 1)
        this.heapify(this.size - 1);
    }
    public T getFront(){
        return (T) this.pqArray[0].Element;
    }
    public T popFront(){
        T poped = (T) this.pqArray[0].Element;
        for(int i=1;i < this.size;i++){
            this.pqArray[i-1] = this.pqArray[i];
        }
        this.size--;
        try{
            if(this.pqArray[0].pRank > this.pqArray[1].pRank){
                Nodep temp = this.pqArray[1];
                this.pqArray[1] = this.pqArray[0];
                this.pqArray[0] = temp;
            }
        }catch (Exception ex){
        }
        return poped;
    }
    public void toArray(){
        System.out.print("[ ");
        for(int i=0;i<this.size;i++){
            System.out.print(this.pqArray[i].pRank +" - "+ this.pqArray[i].Element + ", ");
        }
        System.out.println(" ]");
    }
}

