import LinkedList

def reverse(l):
    prev=None
    temp= l.head
    while(temp!=None):
        d= temp.next
        temp.next= prev
        prev= temp
        temp=d
    l.head=prev


if __name__=="__main__":
    l= LinkedList.LinkedList()
    for i in range(1,10):
        l.insert_start(i)
    l.print_ll()
    print()
    print("After reverse- ")
    reverse(l)
    l.print_ll()
    print()
