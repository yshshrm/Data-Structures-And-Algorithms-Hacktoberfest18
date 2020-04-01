# Node class
class Node:
    # Function to initialize the node object
    def __init__(self, value):
        self.val = value  # Assign value
        self.next = None  # Initialize next as null


# Linked List class
class SingleListNode:
    # Function to initialize the Linked List
    def __init__(self):
        self.head = None

    # Function to traverse until it reaches the most end of the linked lists
    # @return last Node
    def traverse(self):
        if self.head == None:
            return None

        if self.head.next == None:
            return self.head

        temp = self.head
        while(temp.next!=None):
            temp = temp.next

        return temp

    # Function to insert at the last Node
    def insertLast(self, value):
        lastNode = self.traverse()

        target = Node(value)
        if lastNode != None:
            lastNode.next = target

        return target

    # Function to insert at the begining (before head)
    def insert(self, value):
        firstNode = Node(value)
        firstNode.next = self.head
        self.head = firstNode

        return self.head

    # Function to find a Node with value, then return the reference to that Node
    # @return : previous, target
    def search(self, value):
        # If linked lists empty, return None
        if self.head == None:
            return None, None

        # If head contains the value
        if self.head.val == value:
            return None, self.head

        # Try to find the Node
        temp = self.head
        while temp.next != None:
            if temp.next.val == value:
                return temp, temp.next
            temp = temp.next

        # No such Node in the linked list
        return None, None

    # Function to delete a Node with value, then return the reference of that Node
    # @return deleted Node
    def delete(self, value):
        # If linked list is empty
        if self.head == None:
            return None;
        # If head is the target
        if self.head.val == value:
            target = self.head
            self.head = self.head.next
            return target

        # Iterate through linked list to find target Node
        prev, target = self.search(value)

        # If found target, delete
        if target != None:
            prev.next = target.next
            return target

        # If not found, delete
        return None

