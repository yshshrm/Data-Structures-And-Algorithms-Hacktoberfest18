"""
    A queue is a list where you can only insert new items at the back and
    remove items from the front. This ensures that the first item you enqueue
    is also the first item you dequeue. First come, first serve!

    Deques are a generalization of stacks and queues (the name is pronounced
    “deck” and is short for “double-ended queue”). Deques support thread-safe,
    memory efficient appends and pops from either side of the deque with
    approximately the same O(1) performance in either direction.

    Though list objects support similar operations, they are optimized for
    fast fixed-length operations and incur O(n) memory movement costs for
    pop(0) and insert(0, v) operations which change both the size and position
    of the underlying data representation.

"""

from collections import deque


class Queue(object):
    def __init__(self):
        self.queue = deque()

    def is_empty(self):
        return len(self._list) == 0

    def enqueue(self, value):
        self.queue.append(value)

    def dequeue(self):
        try:
            return self.queue.popleft()
        except ValueError:
            return None

    @property
    def front(self):
        try:
            return self.queue[0]
        except ValueError:
            return None

    @property
    def count(self):
        return len(self._list)


if __name__ == '__main__':

    queue = Queue()
    queue.enqueue('ADa')
    queue.enqueue('Steve')
    queue.enqueue('Tim')
    print(queue.dequeue())
    print(queue.dequeue())
    print(queue.dequeue())
    print(queue.dequeue())
