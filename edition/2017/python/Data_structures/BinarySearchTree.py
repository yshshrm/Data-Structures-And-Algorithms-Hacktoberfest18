
class Node:

    def __init__(self, label):
        self.label = label
        self.left = None
        self.right = None

    def getLabel(self):
        return self.label

    def setLabel(self, label):
        self.label = label

    def getLeft(self):
        return self.left

    def setLeft(self, left):
        self.left = left

    def getRight(self):
        return self.right

    def setRight(self, right):
        self.right = right


class BinarySearchTree:

    def __init__(self):
        self.root = None

    def insert(self, label):

        # Create a new Node

        node = Node(label)

        if self.empty():
            self.root = node
        else:
            parent_node = None
            cur_node = self.root

            while True:
                if cur_node is not None:

                    parent_node = cur_node

                    if node.getLabel() < cur_node.getLabel():
                        cur_node = cur_node.getLeft()
                    else:
                        cur_node = cur_node.getRight()
                else:
                    if node.getLabel() < parent_node.getLabel():
                        parent_node.setLeft(node)
                    else:
                        parent_node.setRight(node)
                    break

    def empty(self):
        if self.root is None:
            return True
        return False

    def preOrder(self, cur_node):
        if cur_node is not None:
            print(cur_node.getLabel(), end=" ")

            self.preOrder(cur_node.getLeft())
            self.preOrder(cur_node.getRight())

    def postOrder(self, cur_node):
        if cur_node is not None:
            self.postOrder(cur_node.getLeft())
            self.postOrder(cur_node.getRight())
            print(cur_node.getLabel(), end=" ")

    def inOrder(self, cur_node):
        if cur_node is not None:
            self.inOrder(cur_node.getLeft())
            print(cur_node.getLabel(), end =" ")
            self.inOrder(cur_node.getRight())

    def getRoot(self):
        return self.root



t = BinarySearchTree()
t.insert(4)
t.insert(2)
t.insert(1)
t.insert(3)
t.insert(6)
t.insert(5)
t.insert(7)


t.preOrder(t.getRoot())
print("\n")
t.inOrder(t.getRoot())
print("\n")
t.postOrder(t.getRoot())
print("\n")
