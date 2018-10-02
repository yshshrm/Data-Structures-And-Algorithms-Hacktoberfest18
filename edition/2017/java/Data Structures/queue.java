public class Queue {
    private int size;
    private int[] queueArr;
    private int front = -1;
    private int rear = -1;
    private int totalItems;
 
    public TNQueue(int s) {
        size = s;
        queueArr = new int[s];
    }
 
    public void insert(int i) {
        rear++;
        System.out.println("Inserting "+i);
        queueArr[rear] = i;
        totalItems++;
    }
 
    public int remove() {
        front++;
        totalItems--;
        System.out.println("Removing "+queueArr[front]);
        return queueArr[front];
    }
 
    public boolean isFull() {
        return (totalItems == size);
    }
 
    public boolean isEmpty() {
        return (totalItems == 0);
    }
}