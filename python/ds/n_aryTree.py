# Tree Class
class Node(object):
    def __init__(self, data):
        self.data = data
        self.children = []

    def add_child(self, obj):
        self.children.append(obj)

    # for Printing
    def __str__(self, level=0):
        ret = "\t"*level+repr(self.data)+"\n"
        for child in self.children:
            ret += child.__str__(level+1)
        return ret

p = Node(5)
c1 = Node(6)
c2 = Node(7)
p.add_child(c1)
p.add_child(c2)

c11 = Node(8)
c12 = Node(9)
c21 = Node(10)
c22 = Node(11)
c1.add_child(c11)
c1.add_child(c12)

c2.add_child(c21)
c2.add_child(c22)

# Prints the tree - Branching from left to right
str(p)
print(p)