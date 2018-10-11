package main

import "fmt"

type Stack []int

func main() {
	var st Stack
	for i := 0; i <= 10; i++ {
		st.push(i)
	}
	fmt.Println(st)
	for i := 0; i <= 10; i++ {
		st.pop()
	}
	fmt.Println(st)
}

func (s *Stack) push(x int) {
	*s = append(*s, x)
}

func (s *Stack) pop() int {
	if s.isEmpty() {
		return 0
	}
	d := (*s)[len(*s)-1]
	(*s) = (*s)[:len(*s)-1]
	return d
}

func (s *Stack) isEmpty() bool {
	return len(*s) == 0
}
