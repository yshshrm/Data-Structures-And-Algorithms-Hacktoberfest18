"""
    A double-ended queue. For some reason this is pronounced as "deck".

    A regular queue adds elements to the back and removes from the front.
    The deque also allows enqueuing at the front and dequeuing from the back,
    and peeking at both ends.
"""
from collections import deque


class Deque(object):
    def __init__(self):
        self.deque = deque()

    @property
    def count(self):
        return self.deque.count

    def is_empty(self):
        return self.deque.count == 0

    def enqueue(self, element):
        self.deque.append(element)

    def enqueue_front(self, element):
        self.deque.appendleft(element)

    def dequeue(self):
        if self.is_empty():
            return None
        else:
            return self.deque.popleft()

    def dequeue_back(self):
        if self.is_empty():
            return None
        else:
            return self.deque.pop()

    def peek_front(self):
        return self.deque[0]

    def peek_back(self):
        return self.deque[-1]


if __name__ == '__main__':
    dequeue = Deque()
    dequeue.enqueue(1)
    dequeue.enqueue(2)
    dequeue.enqueue(3)
    dequeue.enqueue(4)

    print(dequeue.dequeue())
    print(dequeue.dequeue_back())

    dequeue.enqueue_front(5)
    print(dequeue.dequeue())
