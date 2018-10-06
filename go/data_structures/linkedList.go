package main

import (
	"fmt"
)

type node struct {
	data interface{}
	next *node
}

func newLinkedList(data interface{}) *node {
	n := new(node)
	n.data = data
	return n
}

func (list *node) insert(data interface{}) {
	for list.next != nil {
		list = list.next
	}
	newNode := new(node)
	newNode.data = data

	list.next = newNode

}

func (list *node) print() {
	for list != nil {
		fmt.Println(list.data)
		list = list.next
	}

}

func main() {
	list := newLinkedList("foo")
	list.insert("bar")
	list.print()
}
