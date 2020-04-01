# Python3 Program to convert a Binary 
# Tree to a Circular Doubly Linked List 

class newNode: 
	def __init__(self, data): 
		self.data = data 
		self.left = self.right = None
		
# A function that appends rightList 
# at the end of leftList. 
def concatenate(leftList, rightList): 
	
	# If either of the list is empty 
	# then return the other list 
	if (leftList == None): 
		return rightList 
	if (rightList == None): 
		return leftList 

	# Store the last Node of left List 
	leftLast = leftList.left 

	# Store the last Node of right List 
	rightLast = rightList.left 

	# Connect the last node of Left List 
	# with the first Node of the right List 
	leftLast.right = rightList 
	rightList.left = leftLast 

	# Left of first node points to 
	# the last node in the list 
	leftList.left = rightLast 

	# Right of last node refers to 
	# the first node of the List 
	rightLast.right = leftList 

	return leftList 

# Function converts a tree to a circular 
# Linked List and then returns the head 
# of the Linked List 
def bTreeToCList(root): 
	if (root == None): 
		return None

	# Recursively convert left and 
	# right subtrees 
	left = bTreeToCList(root.left) 
	right = bTreeToCList(root.right) 

	# Make a circular linked list of single 
	# node (or root). To do so, make the 
	# right and left pointers of this node 
	# point to itself 
	root.left = root.right = root 

	# Step 1 (concatenate the left list 
	#		 with the list with single 
	#		 node, i.e., current node) 
	# Step 2 (concatenate the returned list 
	#		 with the right List) 
	return concatenate(concatenate(left, 
							root), right) 

# Display Circular Link List 
def displayCList(head): 
	print("Circular Linked List is :") 
	itr = head 
	first = 1
	while (head != itr or first): 
		print(itr.data, end = " ") 
		itr = itr.right 
		first = 0
	print() 

# Driver Code 
if __name__ == '__main__': 
	root = newNode(10) 
	root.left = newNode(12) 
	root.right = newNode(15) 
	root.left.left = newNode(25) 
	root.left.right = newNode(30) 
	root.right.left = newNode(36) 

	head = bTreeToCList(root) 
	displayCList(head) 
	
# This code is contributed by PranchalK 
