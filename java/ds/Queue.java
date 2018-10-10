/**
    @Author - Subhajit Das
    University of Engineering and Management, Kolkata
    Date :- 2/10/2018
 */

public class Queue{
    private int arr[],len;
    private int front,rear;

    public Queue(int len){
        this.len = len;
        arr = new int[this.len];
        front = -1;
        rear = -1;
    }

    public void insert(int element){
        // To insert elements inside queue.
        if (front == -1 && rear == -1){
            rear++;
            front++;
            arr[rear] = element;
            return;
        }
        else if(rear == len-1){
            System.out.println("Queue Full");
            return;
        }
        rear++;
        arr[rear]=element;
    }

    public int remove(){
        // To remove elements from queue.
        if(front == -1){
            System.out.println("Queue Empty");
            return Integer.MIN_VALUE;
        }
        int ret = arr[front];
        front++;
        if (front>rear){
            front = -1;
            rear = -1;
        }
        return ret;
    }

    public void display(){
        // To display all contents of queue.
        if (front == -1 && rear == -1){
            System.out.println("Queue Empty");
            return;
        }
        System.out.println("Elements in Queue are:\n");
        for(int i=front;i<=rear;i++){
            System.out.print(arr[i]+"\t");
        }
        System.out.println();
    }

    public static void main(String args[]){
        //Driver code to check the code.
        Queue que = new Queue(4);
        que.insert(1);
        que.insert(2);
        que.insert(3);
        que.insert(4);
        que.insert(5);
        que.display();
        System.out.println(que.remove());
        System.out.println(que.remove());
        que.display();
        System.out.println(que.remove());
        System.out.println(que.remove());
        System.out.println(que.remove());
    }

}