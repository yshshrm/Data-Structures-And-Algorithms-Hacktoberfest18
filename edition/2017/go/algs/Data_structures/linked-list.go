package algs

import "fmt"

type LinkedList struct {
	head *listNode
	last *listNode
	size int
}
type listNode struct {
	val int
	next *listNode
	prev *listNode
}
func (l *LinkedList) Push(value int) int {
	return l.Add(value)
}
func (l *LinkedList) Pop() (int, bool) {
	if l.size == 0 {
		return 0, false
	}
	val := l.head.val
	if l.size == 1 {
		l.head = nil
		l.last = nil
	} else {
		l.head = l.head.next
	}
	l.size--
	return val, true
}
func (l *LinkedList) Add(value int) int {
	newNode := listNode{val:value}
	if l.head == nil {
		l.head = &newNode
		l.last = l.head
	} else {
		l.last.next = &newNode
		newNode.prev = l.last
		l.last = &newNode
	}
	l.size++
	return value
}
func (l *LinkedList) Remove(value int) bool {
	if l.size == 0 {
		return false
	} else if l.head.val == value {
		if l.size == 1 {
			l.head = nil
			l.last = nil
		} else {
			l.head.next.prev = nil
			l.head = l.head.next
			l.last = l.head
		}
		l.size--
		return true
	}
	iter := l.head.next
	for iter != nil {
		if iter.val == value {
			if iter.next != nil {
				iter.prev.next = iter.next
				iter.next.prev = iter.prev
			} else {
				iter.prev.next = nil
				l.last = iter.prev
			}
			l.size--
			return true
		}
		iter = iter.next
	}
	return false
}
func (l *LinkedList) find(value int) *listNode {
	if l.size == 0 {
		return nil
	}
	iter := l.head
	for iter != nil {
		if iter.val == value {
			return iter
		}
		iter = iter.next
	}
	return nil
}
func (l *LinkedList) Contains(value int) bool {
	if(l.find(value) != nil) {
		return true
	} else {
		return false
	}
}
func (l *LinkedList) Exchange(valueA int, valueB int) bool {
	valAnode := l.find(valueA)
	valBnode := l.find(valueB)
	if valAnode == nil || valBnode == nil {
		return false
	}
	valAnode.val = valueB
	valBnode.val = valueA
	return true
}
func (l *LinkedList) SwapPointers(valueA int, valueB int) bool {
	valAnode := l.find(valueA)
	valBnode := l.find(valueB)
	if valAnode == nil || valBnode == nil {
		return false
	}
	if valBnode.prev != nil {
		valBnode.prev.next = valAnode
	} else {
		l.head = valAnode
	}
	if valBnode.next != nil {
		valBnode.next.prev = valAnode
	} else {
		l.last = valAnode
	}
	if valAnode.prev != nil {
		valAnode.prev.next = valBnode
	} else {
		l.head = valBnode
	}
	if valAnode.next != nil {
		valAnode.next.prev = valBnode
	} else {
		l.last = valBnode
	}
	valAprev := valAnode.prev
	valAnext := valAnode.next
	valAnode.prev = valBnode.prev
	valAnode.next = valBnode.next
	valBnode.prev = valAprev
	valBnode.next = valAnext
	return true
}
func (l *LinkedList) PrintList() {
	iter := l.head
	for iter != nil {
		fmt.Println(iter.val)
		iter = iter.next
	}
}