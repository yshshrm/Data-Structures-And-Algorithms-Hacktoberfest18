package main

import "fmt"

type Node struct {
	data interface{}
	next *Node
}

// returns number of nodes from end, target node
func (node *Node) helper(n int) (int, *Node) {
	if node == nil {
		return 0, nil
	}
	numFromLast, targetNode := node.next.helper(n)
	if targetNode != nil {
		return 0, targetNode
	}
	if numFromLast == n {
		return 0, node
	}
	return numFromLast + 1, nil
}

// returns n-th node from end
func (node *Node) Runner(n int) *Node {
	_, targetNode := node.helper(n)
	return targetNode
}

func main() {
	head := &Node{1,
		&Node{2,
			&Node{3,
				&Node{4,
					&Node{5,
						&Node{6, nil}}}}}}

	// get third node from end
	fmt.Println(head.Runner(3))
}
