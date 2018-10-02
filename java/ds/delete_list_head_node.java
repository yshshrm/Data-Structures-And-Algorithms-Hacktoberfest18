java.util.*;

public class delete_list_head_node() {

    public ListNode deleteHeadNode(ListNode head) {
        if(head == null) {
            return null;
        }
    
        ListNode tempNode = null;
    
        while (head.next != null) {
            tempNode = head.next;
            head.next  = null;
        }
        return tempNode;
    }
}

