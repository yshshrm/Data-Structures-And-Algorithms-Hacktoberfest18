
# coding: utf-8

# In[7]:


import random 
  
# Creation of a node
class Node: 
  
    # Constructor to initialize the node object 
    def __init__(self, data): 
        self.data= data 
        self.next = None

# Linking of nodes        
class LinkedList: 
  
    # function to initialize head 
    def __init__(self): 
        self.head = None
  
    # function to print a random node from a linkd list 
    def printRandom(self): 
  
        # Checks if list is empty  
        if self.head is None: 
            return
        if self.head and not self.head.next: 
            print("Randomly selected key is %d" %(self.head.data))
  
        # Use a different seed value so that we don't get  
        # same result each time we run this program 
        random.seed() 
  
        # Initialize result as first node 
        result = self.head.data 
  
        current = self.head.next 
        n = 2 
        while(current is not None): 
              
            if (random.randrange(n) == 0 ): 
                result = current.data  
  
            # Move to next node 
            current = current.next
            n += 1
  
        print ("Randomly selected key is %d" %(result))
          
    # function to insert a new node at the beginning 
    def push(self, new_data): 
        new_node = Node(new_data) 
        new_node.next = self.head 
        self.head = new_node 
  
    # Utility function to print the LinkedList 
    def printList(self): 
        temp = self.head 
        while(temp): 
            print (temp.data), 
            temp = temp.next

            
llist = LinkedList() 
llist.push(51) 
llist.push(100) 
llist.push(60) 
llist.push(89) 
llist.push(32)
llist.push(87) 
llist.push(55) 
llist.push(72)
llist.push(90) 
llist.push(93) 
llist.push(40)
llist.printRandom() 

