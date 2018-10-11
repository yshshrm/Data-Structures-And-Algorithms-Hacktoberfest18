// Java code for detecting loops in a linked list
// Based on Floyd Cycle algorithm for loop detection
// Using the concept of fast pointer and slow pointers
public class LinkedListLoopDetection{
    static class Node{
        int data;
        Node next;

        public Node(int data){
            this.data = data;
            this.next = null;
        }
    }
    
    private static Node makeNode(int a){
        Node node = new Node(a);
        return node;
    }

    private static Node makeLinkedList(int[] inputValues){
        Node head, temp;
        head = makeNode(inputValues[0]);
        temp = head;
        for(int i = 1; i<inputValues.length; i++){
            Node newNode = makeNode(inputValues[i]);
            temp.next = newNode;
            temp = newNode;
        }
        return head;
    }

    private static Node makeLinkedListWithLoop(int[] inputValues){
        Node head, temp;
        head = makeNode(inputValues[0]);
        temp = head;
        for(int i = 1; i<inputValues.length; i++){
            Node newNode = makeNode(inputValues[i]);
            temp.next = newNode;
            temp = newNode;
        }

        //defining range of random no.
        int max = inputValues.length - 1;
        int min = 0;
        int range = max - min + 1;
        int randomNo = (int)(Math.random()*range) + min;
        Node temp2 = head;
        System.out.println(randomNo);
        for(int i = 0; i<randomNo; i++){
            temp2 = temp2.next;
        }
        temp.next = temp2;  //because temp points to the last node of the list;
        return head;
    }

    //method that detects loop in the linkedList
    public static boolean detectLoop(Node head){
        Node slowPtr = head, fastPtr = head;
        while(slowPtr != null && fastPtr != null && fastPtr.next != null){
            slowPtr = slowPtr.next;
            fastPtr = fastPtr.next.next;
            if(slowPtr == fastPtr){
                System.out.println("Found loop");
                return true;
            }
        }
        System.out.println("Has no loop");
        return false;
    }

    public static void main(String args[]){
        int inputValues[] = {1,54,6,23,8,5};
        Node head = makeLinkedList(inputValues);
        Node headWithLoop = makeLinkedListWithLoop(inputValues);
        detectLoop(head);
        detectLoop(headWithLoop);
    }
}