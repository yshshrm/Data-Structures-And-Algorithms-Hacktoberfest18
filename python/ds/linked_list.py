class Node:
    def __init__(self, data):
        self.data = data
        self.nextnode = None

class Start_node:
    def __init__(self):
        self.headval = None

    def traversal(self):
        self.printval = self.headval
        while self.printval is not None:
            print(self.printval.data, self.printval.nextnode)
            self.printval = self.printval.nextnode

    def insert_begining(self, newdataa):
        
        n = Node(newdataa)
        n.nextnode = self.headval
        self.headval = n

    def insert_end(self, newdata):
        printval = self.headval
        while printval is not None:
            if printval.nextnode is None:
                n = Node(newdata)
                n.nextnode = None
                printval.nextnode = n
                break
            
            printval = printval.nextnode
        
    def insert_between(self, prev, newdata):
        printval = self.headval
        while printval is not None:
            if printval.data == prev :
                n = Node(newdata)
                n.nextnode = printval.nextnode
                printval.nextnode = n
            printval = printval.nextnode

    def remove(self, data):
        printval = self.headval
        prev = None
        while printval.data != data:
            prev = printval
            printval = printval.nextnode
        
        if prev is None:
            self.headval = printval.nextnode

        else:
            prev.nextnode = printval.nextnode
            
        




list1 = Start_node()
list1.headval = Node('mon')
e2 = Node('tue')
e3 = Node('wed')
e4 = Node('thu')

list1.headval.nextnode = e2
e2.nextnode = e3
e3.nextnode = e4

list1.traversal()

print()
list1.insert_begining('week')
list1.traversal()

list1.insert_end('last')
print()
list1.traversal()

list1.insert_between('week', 'middle day')
print()
list1.traversal()

list1.remove('last')
print()
list1.traversal()
