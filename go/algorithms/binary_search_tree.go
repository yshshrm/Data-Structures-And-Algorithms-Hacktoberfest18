package main

import "fmt"

type Node struct {
	Key   int
	Right *Node
	Left  *Node
}

func (n *Node) Search(key int) bool {
	// This is our base case. If n == nil, `key`
	// doesn't exist in our binary search tree.
	if n == nil {
		return false
	}

	if n.Key < key { // move right
		return n.Right.Search(key)
	} else if n.Key > key { // move left
		return n.Left.Search(key)
	}

	// n.Key == key, we found it!
	return true
}

func (n *Node) Delete(key int) *Node {
	// search for `key`
	if n.Key < key {
		n.Right = n.Right.Delete(key)
	} else if n.Key > key {
		n.Left = n.Left.Delete(key)
		// n.Key == `key`
	} else {
		if n.Left == nil { // just point to opposite node
			return n.Right
		} else if n.Right == nil { // just point to opposite node
			return n.Left
		}

		// if `n` has two children, you need to
		// find the next highest number that
		// should go in `n`'s position so that
		// the BST stays correct
		min := n.Right.Min()

		// we only update `n`'s key with min
		// instead of replacing n with the min
		// node so n's immediate children aren't orphaned
		n.Key = min
		n.Right = n.Right.Delete(min)
	}
	return n
}

func (n *Node) Min() int {
	if n.Left == nil {
		return n.Key
	}
	return n.Left.Min()
}

func (n *Node) Max() int {
	if n.Right == nil {
		return n.Key
	}
	return n.Right.Max()
}

func (n *Node) Insert(key int) {
	if n.Key < key {
		if n.Right == nil { // we found an empty spot, done!
			n.Right = &Node{Key: key}
		} else { // look right
			n.Right.Insert(key)
		}
	} else if n.Key > key {
		if n.Left == nil { // we found an empty spot, done!
			n.Left = &Node{Key: key}
		} else { // look left
			n.Left.Insert(key)
		}
	}
	// n.Key == key, don't need to do anything
}

func main() {
	tree := &Node{
		Key:   6,
		Right: nil,
		Left:  nil,
	}
	fmt.Println(tree)
}
