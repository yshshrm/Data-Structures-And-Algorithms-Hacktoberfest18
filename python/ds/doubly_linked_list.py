class Node:
    def __init__(self, data):
        self.data = data
        self.prev = None
        self.next = None


class DLinkedList:
    def __init__(self):
        self.head = None
        self.tail = None
        self.prob = self.head

    def probn(self, data):
        if data <= self.prob.data:
            while data <= self.prob.data and self.prob is not self.head:
                print(data, self.prob.data, 'a')
                self.prob = self.prob.prev
        elif data > self.prob.data:
            while data > self.prob.data and self.prob is not self.tail:
                self.prob = self.prob.next
                print(data, self.prob.data, 'b')
            self.prob = self.prob.prev

    def insert(self, data):
        newNode = Node(data)

        if self.head is None:
            self.head = newNode
            self.tail = newNode
            self.prob = self.head
        elif data < self.head.data:
            newNode.next = self.head
            self.head.prev = newNode
            self.head = newNode
        elif data > self.tail.data:
            self.tail.next = newNode
            newNode.prev = self.tail
            self.tail = newNode
        else:
            self.probn(data)

            newNode.next = self.prob.next
            self.prob.next.prev = newNode
            self.prob.next = newNode
            newNode.prev = self.prob

    def delete(self, data):
        if data == self.head.data:
            tmp = self.head
            self.head = self.head.next
            del tmp
        elif data == self.tail.data:
            tmp = self.tail
            self.tail = self.tail.prev
            del tmp
        else:
            self.probn(data)
            if self.prob == self.head or self.prob.next == self.tail or self.prob.data != data:
                print("Error: " + str(data) + " is not in the list.")
            else:
                self.prob = self.prob.next
                self.prob.prev.next = self.prob.next
                self.prob.next.prev = self.prob.prev
                self.prob = self.prob.prev

    def printdl(self):
        tmp = self.head
        while tmp is not self.tail:
            print(tmp.data, end=' ')
            tmp = tmp.next
	print(self.tail.data)



l = DLinkedList()
l.insert(2)
l.insert(11)
l.insert(12)
l.insert(7)
l.insert(8)
l.insert(39)
l.insert(10)
l.insert(1)
l.insert(14)
l.insert(3)
l.delete(5)
l.printdl()

