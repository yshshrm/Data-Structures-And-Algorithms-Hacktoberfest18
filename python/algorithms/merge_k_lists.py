# description: https://leetcode.com/problems/merge-k-sorted-lists/description/


# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x, next_node=None):
        self.val = x
        self.next = next_node

    def __str__(self):
        # pretty print
        if self.next is not None:
            return str(self.val) + '->' + str(self.next)
        else:
            return str(self.val)


class Solution(object):
    def mergeKLists(self, lists):
        """
        :type lists: List[ListNode]
        :rtype: ListNode
        """
        result_head, cur_node = None, None
        first_elem = True
        pointers = [l for l in lists if l]    # filter empty lists
        while pointers:
            # find min value of current pointers
            min_idx = None
            for idx, pointer in enumerate(pointers):
                if min_idx is None or pointer.val < pointers[min_idx].val:
                    min_idx = idx

            # add current min value to result list
            new_elem = ListNode(pointers[min_idx].val)
            if first_elem:
                cur_node = result_head = new_elem
                first_elem = False
            else:
                cur_node.next = new_elem
                cur_node = new_elem

            # make a step over pointer
            if pointers[min_idx].next is not None:
                pointers[min_idx] = pointers[min_idx].next
            else:
                pointers.pop(min_idx)

        return result_head


# code for testing solution

def generate_list_by_values(values):
    cur_node = None
    for v in values[::-1]:
        cur_node = ListNode(v, next_node=cur_node)
    return cur_node


if __name__ == "__main__":
    example_lists_str = "1->4->5\n1->3->4\n2->6"
    example_input = []
    for list_str in example_lists_str.split('\n'):
        example_input.append(generate_list_by_values([
            int(x) for x in list_str.split('->')
        ]))

    expected_output = generate_list_by_values([
        int(x) for x in "1->1->2->3->4->4->5->6".split('->')
    ])

    result = Solution().mergeKLists(example_input)
    assert expected_output == result
