def reverseList(list):

       #Initializing values
       prev = None
       curr = list.head
       nex = curr.getNextNode()
  
       #looping
       while curr:
           #reversing the link
           curr.setNextNode(prev)     

           #moving to next node      
           prev = curr
           curr = nex
           if nex:
               nex = nex.getNextNode()

       list.head = prev
