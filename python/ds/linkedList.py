class Node:

    def __init__(self,data):
        self.data=data
        self.next=None

    def strnode(self):
        print(self.data)

class LinkedList:
    def __init__(self):
        self.numnodes=0
        self.head=None

    def insertFirst(self,data):
        newnode =Node(data)
        newnode.next=self.head
        self.head=newnode
        self.numnodes +=1

    def insertLast(self,data):
        newnode=Node(data)
        newnode.next =None
        if self.head ==None:
            self.head= newnode
            return
        lnode=self.head
        while lnode.next != None:
            lnode=lnode.next
        lnode.next=newnode
        self.numnodes +=1

    def remFirst(self):
        cnode=self.head
        self.head =cnode.next
        cnode.next=None
        del cnode
        self.numnodes -=1

    def remLast(self):
        lnode = self.head
        while lnode.next!=None:
            pnode=lnode
            lnode=lnode.next
        pnode.next=None
        del lnode
        self.numnodes -=1

    def getFirst(self):
        lnode =self.head
        return lnode.data
    def getLast(self):
        lnode = self.head

        while lnode.next !=None:
            lnode=lnode.next
            return lnode.data

    def print_list(self):
        lnode = self.head
        while lnode:
            lnode.strnode()
            lnode = lnode.next

    def getSize(self):
        return self.numnodes


a=LinkedList()
a.insertLast(10)
a.insertFirst(12)
a.insertFirst(14)
a.getSize()
a.insertLast(9)
a.print_list()
a.remFirst()
a.remLast()
a.print_list()

