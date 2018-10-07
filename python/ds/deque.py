
# this is written in Python 3.6.2
# tested in jupyter notebook
class Deque:
    # creates new deque
    def __init__(self):
        self.items = []
    # tests whether deque is empty
    def isEmpty(self):
        return self.items == []
    # adds front item to deque
    def addFront(self, item):
        self.items.append(item)
    # adds rear item to deque
    def addRear(self, item):
        self.items.insert(0,item)
    # removes front item and returns modifed deque
    def removeFront(self):
        return self.items.pop()
    # removes rear item and returns modified deque
    def removeRear(self):
        return self.items.pop(0)
    #returns size of deque 
    def size(self):
        return len(self.items)