// This is also the solution to leetcode problem 23

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        if(lists.length == 0 ) return null;
        if(lists.length == 1) return lists[0];
        ListNode start = lists[0];

        for(int i = 1;i<lists.length; i++){
            if(lists[i] == null) continue;
            start = sorted(start,lists[i]);          
        }
        
        return start;
    }
    
    public void helper(ListNode l){
        while(l!=null){
            System.out.print(l.val +" ");
            l=l.next;
        }
        System.out.println();
    }
    
    public ListNode sorted(ListNode l1, ListNode l2){
        if(l1 == null) return l2;
        ListNode temp = new ListNode(0);
        ListNode head = null;
        if(l1.val <= l2.val){
                head = l1 ;
            }else{
                head = l2;
            }
            //helper(head);  
            while(l1!=null && l2!=null){
                
                if(l1.val <= l2.val){
                    temp.next=l1;
                    temp = l1;
                    l1=l1.next;
                }else{
                    temp.next=l2;
                    temp = l2;
                    l2=l2.next;
                }
                
                    
            }
            
            if(l1 != null){
                temp.next = l1;
            }
            
            if(l2 != null){
                temp.next = l2;
            }
        
        return head;
        
    }
    
    
}
