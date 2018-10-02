class Stack:

    def __init__(self):
        self._data = []
    
    def push(self, x):
        self._data.append(x)
    
    def pop(self):
        x = self._data[len(self._data) - 1]
        del self._data[len(self._data) - 1]
        return x
    
    def peek(self):
        return self._data[len(self._data) - 1]
    
    def empty(self):
        self._data = []
    

def test():
    stack = Stack()
    stack.push(1)
    stack.push(2)
    stack.push(3)
    print(stack.pop())
    print(stack.pop())
    stack.empty()
    stack.push(4)
    stack.push(5)
    print(stack.peek())
    stack.push(6)
    print(stack.pop())
    print(stack.pop())
    print(stack.pop())


if __name__ == '__main__':
    test()
