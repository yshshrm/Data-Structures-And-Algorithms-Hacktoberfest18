/*
Linked List is a data structure having link or address to the next and/or previous
node along with some data. Floyd's algorithm is used to find a loop in a liked list.
For this 2 pointers are used a slow pointer which moves by one and a fast pointer which
 moves by two. If loop is present the fast and slow pointer will meet at a node thus
 helping in loop detection*/
 class FloydAlgo {
   public boolean findLoop(Node head)
      {
        Node slow = head, fast = head;
        while (slow != null && fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
            if (slow == fast)
                return true;//Loop is found
      return false;
    }
}
