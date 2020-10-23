/** Converting binary numbers in an array list to int **/
public int getDecimalValue(ListNode head) {
        int num = head.val;
        while (head.next != null) {
            num = (num << 1) | head.next.val;
            head = head.next;    
        }
        return num;
    }
