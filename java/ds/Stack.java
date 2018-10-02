/**
    @Author - Subhajit Das
    University of Engineering and Management, Kolkata
    Date :- 2/10/2018
 */

public class Stack {
    private int arr[],len;
    private int pointer;

    public Stack(int len){
        pointer = -1;
        this.len = len;
        arr = new int[this.len];
    }

    public void push(int element){
        // For pushing element in a stack.
        if (pointer == len-1){
            System.out.println("Stack Overflow");
            return;
        }
        pointer++;
        arr[pointer] = element;
    }

    public int pop(){
        // For popping element from the stack. Return min int value if stack underflow.
        if(pointer == -1){
            System.out.println("Stack Underflow");
            return Integer.MIN_VALUE;
        }
        pointer--;
        return arr[pointer+1];
    }

    public void display(){
        // To display the contents of a stack.
        if (pointer == -1){
            System.out.println("Stack empty");
            return;
        }
        System.out.println("Contents of stack are :\n");
        for(int i=0;i<=pointer;i++)
            System.out.print(arr[i]+"\t");
        System.out.println();
    }
}