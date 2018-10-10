public class insert_node_head_list() {

  public ListNode insertAtHead(ListNode head, int data) {
    ListNode newHeadNode = new ListNode(data);
    if(head == null) { 
        head = newHeadNode;
    } else {
        newHeadNode.next = head;
        head = newHeadNode;
    }
    return head;
  } 

}
