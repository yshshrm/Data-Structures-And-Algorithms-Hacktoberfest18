# https://leetcode.com/problems/reorder-list/description/


# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x, next_node=None):
        self.val = x
        self.next = next_node

    def __str__(self):
        if self.next is not None:
            return str(self.val) + '->' + str(self.next)
        else:
            return str(self.val)


def shrink_list_tail(node):
    if node.next is None:
        return node
    while node.next is not None:
        if node.next.next is None:
            # node.next is the last element
            result = node.next
            node.next = None
            return result
        else:
            node = node.next


class Solution(object):
    def reorder_list(self, head):
        """
        :type head: ListNode
        :rtype: void Do not return anything, modify head in-place instead.
        """

        cur_node = head
        while cur_node is not None and cur_node.next is not None and cur_node.next.next is not None:
            tail = shrink_list_tail(cur_node)
            tail.next = cur_node.next
            cur_node.next = tail
            cur_node = cur_node.next.next

# code for testing solution


def generate_list_by_values(values):
    cur_node = None
    for v in values[::-1]:
        cur_node = ListNode(v, next_node=cur_node)
    return cur_node


if __name__ == "__main__":
    example_input = generate_list_by_values([int(x) for x in "1->2->3->4".split('->')])
    expected_output = generate_list_by_values([int(x) for x in "1->4->2->3".split('->')])

    # in-place
    Solution().reorder_list(example_input)
    print(expected_output)
    print(example_input)

    example_input = generate_list_by_values([int(x) for x in "1->2->3->4->5".split('->')])
    expected_output = generate_list_by_values([int(x) for x in "1->5->2->4->3".split('->')])

    # in-place
    Solution().reorder_list(example_input)
    print(expected_output)
    print(example_input)
