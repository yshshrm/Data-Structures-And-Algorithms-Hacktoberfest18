class queue(object):
    def __init__(self, lst = []):
        self.queue = list(lst)

    def get(self):
        if len(self.queue) == 0:
            return
        value = self.queue.pop(0)
        return value

    def put(self, value):
        self.queue.append(value)
    
    def empty(self):
        if len(self.queue) == 0:
            return True
        return False

    def size(self):
        return len(self.queue)
    
    def __str__(self):
        return self.queue.__str__()
