# RG
# 11.1


class Node:

    def __init__(self, val):
        self.val = val
        self.next = None


class Queue:

    def __init__(self):
        self.start = None
        self.end = None
        self.count = 0

    def enqueue(self, val):
        new_node = Node(val)
        if self.start is None:
            self.start = new_node
            self.end = new_node
        else:
            self.end.next = new_node
            self.end = new_node
        self.count += 1

    def dequeue(self):
        if self.start is None:
            return
        elif self.start == self.end:
            self.start = None
            self.end = None
        else:
            self.start = self.start.next
        self.count -= 1

    def get_size(self):
        return self.count

    def is_empty(self):
        return self.count == 0

    def front(self):
        if self.start is None:
            return None
        return self.start.val

    def __len__(self):
        return self.count

    def __str__(self):
        s = ''
        current_node = self.start
        while current_node is not None:
            s += str(current_node.val)
            current_node = current_node.next
            if current_node is not None:
                s += ', '
        return s