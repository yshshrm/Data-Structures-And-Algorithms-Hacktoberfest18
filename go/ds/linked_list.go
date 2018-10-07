package ds

import (
	"fmt"
	"strings"
)

// LinkedListElement defines how any element of the linked list looks like.
type LinkedListElement struct {
	Value int
	Next  *LinkedListElement
	Prev  *LinkedListElement
}

// LinkedList defines how the linked list is represented.
type LinkedList struct {
	Head *LinkedListElement
}

// NewLinkedList returns a new linked list.
func NewLinkedList() *LinkedList {
	return &LinkedList{
		Head: nil,
	}
}

// Add inserts an element at the tail of the linked list.
func (ll *LinkedList) Add(val int) {
	el := &LinkedListElement{
		Value: val,
		Next:  nil,
	}
	if ll.Head == nil {
		el.Prev = nil
		ll.Head = el
		return
	}
	cursor := ll.Head
	for cursor.Next != nil {
		cursor = cursor.Next
	}
	cursor.Next = el
	el.Prev = cursor
	return
}

// Remove deletes the first linked list element that has a specific value.
func (ll *LinkedList) Remove(val int) {
	cursor := ll.Head
	if cursor == nil {
		return
	}
	if cursor.Value == val {
		ll.Head = cursor.Next
		ll.remove(cursor)
		return
	}
	for cursor.Next != nil {
		if cursor.Value == val {
			cursor.Prev.Next = cursor.Next
			cursor.Next.Prev = cursor.Prev
			ll.remove(cursor)
			return
		}
		cursor = cursor.Next
	}
	if cursor.Value == val {
		cursor.Prev.Next = nil
		ll.remove(cursor)
	}
	return
}

func (ll *LinkedList) remove(el *LinkedListElement) {
	el.Next = nil
	el.Prev = nil
}

// Len returns the length of the linked list.
func (ll *LinkedList) Len() int {
	var len int
	cursor := ll.Head
	for cursor != nil {
		cursor = cursor.Next
		len++
	}
	return len
}

// String implements the stringer interface.
func (ll *LinkedList) String() string {
	strBuilder := strings.Builder{}
	cursor := ll.Head
	for cursor.Next != nil {
		strBuilder.WriteString(fmt.Sprintf("%d --> ", cursor.Value))
		cursor = cursor.Next
	}
	strBuilder.WriteString(fmt.Sprintf("%d", cursor.Value))
	return strBuilder.String()
}
