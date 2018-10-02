public class delete_list_at_tail_node() {
  
  public ListNode deleteAtTail(ListNode head) {
      if(head == null || head.next == null) {
          return null;
      }

      ListNode curr = head;
      ListNode prev = curr;

      while(curr.next != null) {
          prev = curr;
          curr = curr.next;
      }

      prev.next = null;
      return head;

  }
}


