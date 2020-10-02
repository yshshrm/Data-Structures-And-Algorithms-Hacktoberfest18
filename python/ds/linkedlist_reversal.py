# Python program to reverse a linked list 
#Note: insertion of node happens in the beginning

# Node class 
class Node: 

	# Constructor to initialize the node object 
	def __init__(self, data): 
		self.data = data 
		self.next = None

class LinkedList: 

	# Function to initialize head 
	def __init__(self): 
		self.head = None

	# Function to reverse the linked list 
	def reverse(self): 
		prev = None
		cur = self.head 
		while(cur is not None): 
			next = cur.next
			cur.next = prev 
			prev = cur
			cur = next
		self.head = prev 
		
	# Function to insert a new node at the beginning 
	def push(self, new_data): 
		new_node = Node(new_data) 
		new_node.next = self.head 
		self.head = new_node 

	# Utility function to print the LinkedList 
	def printList(self): 
		temp = self.head 
		while(temp): 
			print(temp.data)
			temp = temp.next


# Driver program to test above functions 
llist = LinkedList() 
llist.push(10) 
llist.push(2) 
llist.push(60) 
llist.push(17) 
llist.push(50) 

print("Given Linked List: ")
llist.printList() 
llist.reverse() 
print("\nReversed Linked List: ")
llist.printList() 


