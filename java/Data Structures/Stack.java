public class Stack{
    int arr[];
    int size;
    int top;
    public Stack(int size) {
        this.size = size;
        arr = new int[this.size];
        top = -1;
    }
    public void push(int element) {
        if(top < size)
            arr[++top] = element;
        else
            System.out.println("Stack overflow");
    }
    public int pop() {
        if(top > -1)
            return arr[top--];
        else{
            System.out.println("Stack underflow");
            return 0;
        }
    }
}
