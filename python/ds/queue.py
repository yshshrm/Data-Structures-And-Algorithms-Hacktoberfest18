# this is written in Python 3.6.2
# tested in jupyter notebook


class Queue:
    # creates a new queue
    def __init__(self):
        self.items = []

    #checks for empty queue
    def isEmpty(self):
        return self.items == []
    # inserts a new item onto the queue
    def enqueue(self, item):
        self.items.insert(0,item)
    # front item is removed from the queue
    def dequeue(self):
        return self.items.pop()

    # returns the length of the queue 
    def size(self):
        return len(self.items)
