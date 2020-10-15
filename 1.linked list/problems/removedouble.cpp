/*
Remove all elements from a linked list of integers that have value val.
Input:  1->2->6->3->4->5->6, val = 6
Output: 1->2->3->4->5

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* r=head;
        while(r)
        {
            while(r->next && r->next->val==val)
            {
                r->next=r->next->next;
            }
            r=r->next;
            
        }
        if(head)
        {
            if(head->val==val)
                head=head->next;
        }
        return head;
        
    }
};
