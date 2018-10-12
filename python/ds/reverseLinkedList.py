class ListNode:
  def __init__(self, x):
      self.val = x
      self.next = None

def reverseList(self, A):
        prev = None
        current = A

        if current == None:
            return current

        next = current.next

        while current != None:
            current.next = prev
            prev = current
            current = next
            if next != None:
                next = next.next

        return prev
