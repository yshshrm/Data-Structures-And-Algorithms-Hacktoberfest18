#!/usr/bin/env python

# Python code for Loop detection in a linkedList using Floyd Cycle Detection Algorithm
# Coded for python3
# Written by: Pritish Sehzpaul Oct-12-2018

class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None
    
    # function that creates a new node
    def push(self, data):
        node = Node(data)
        node.next = self.head
        self.head = node

    def detectLoop(self):
        slow_ptr = self.head
        fast_ptr = self.head

        while(slow_ptr and fast_ptr and fast_ptr.next):
            slow_ptr =slow_ptr.next
            fast_ptr = fast_ptr.next.next
            if slow_ptr == fast_ptr:
                print("Found loop")
                return True
        
        print("Has no loop")
        return False

# Program execution begins here
linked_list = LinkedList()
linked_list.push(9)
linked_list.push(23)
linked_list.push(99)
linked_list.push(3)
linked_list.push(44)
linked_list.push(25)
# so the linked list will be 25 -> 44 -> 3 -> 99 -> 23 -> 9
# and head will be node with value 25
val1 = linked_list.detectLoop()

# Creating a loop for testing
linked_list.head.next.next.next.next.next.next = linked_list.head.next
# now the linked list will be 25 -> 44 -> 3 -> 99 -> 23 -> 9
#                                   |                      |
#                                   ------------------------
val2 = linked_list.detectLoop()
# print(val1," ",val2)