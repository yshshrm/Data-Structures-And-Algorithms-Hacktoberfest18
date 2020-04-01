class node:
	def __init__(self,data=None):
		self.data=data
		self.next=None

class linked_list:
	def __init__(self):
		self.head=node()

	# Adds new node containing 'data' to the end of the linked list.
	def append(self,data):
		new_node=node(data)
		cur=self.head
		while cur.next!=None:
			cur=cur.next
		cur.next=new_node

	# Returns the length (integer) of the linked list.
	def length(self):
		cur=self.head
		tot=0
		while cur.next!=None:
			tot+=1
			cur=cur.next
		return tot 

	# Prints out the linked list in traditional Python list format. 
	def display(self):
		elements=[]
		cur_node=self.head
		while cur_node.next!=None:
			cur_node=cur_node.next
			elements.append(cur_node.data)
		print(elements)

	# Returns the value of the node at 'index'. 
	def get(self,index):
		if index>=self.length() or index<0: # added 'index<0' post-video
			print("ERROR: 'Get' Index out of range!")
			return None
		cur_idx=0
		cur_node=self.head
		while True:
			cur_node=cur_node.next
			if cur_idx==index: return cur_node.data
			cur_idx+=1

	# Deletes the node at index 'index'.
	def erase(self,index):
		if index>=self.length() or index<0: # added 'index<0' post-video
			print("ERROR: 'Erase' Index out of range!")
			return 
		cur_idx=0
		cur_node=self.head
		while True:
			last_node=cur_node
			cur_node=cur_node.next
			if cur_idx==index:
				last_node.next=cur_node.next
				return
			cur_idx+=1
my_list=linked_list()
my_list.append(69)
my_list.append(24)
my_list.append(45)
my_list.append(34)
my_list.append(654)
my_list.append(345)

my_list.display()
my_list.erase(4)
my_list.display()