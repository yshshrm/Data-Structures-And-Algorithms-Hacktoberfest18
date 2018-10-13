package main

import "fmt"

type stack struct {
	pile [10]int
	top  int
}

func hanoiTower() {
	var s1, s2, s3 stack
	e := getHeight()
	fmt.Printf("after get height : %v \n", e)
	for i := e; i > 0; i-- {
		fmt.Printf("push  : %v \n", i)
		s1.push(i)
	}
	fmt.Printf("begin s1 is : %v \n", s1)
	fmt.Printf("begin s2 is : %v \n", s2)
	fmt.Printf("begin s3 is : %v \n", s3)
	move(&s1, &s3, &s2, e)
	fmt.Printf("begin s1 is : %v \n", s1)
	fmt.Printf("begin s2 is : %v \n", s2)
	fmt.Printf("begin s3 is : %v \n", s3)
}

func (x *stack) push(v int) {
	x.pile[x.top] = v
	x.top++
}

func (x *stack) pop() int {
	v := x.pile[x.top-1]
	x.pile[x.top-1] = 0
	x.top--
	println("in pop : v = ", v)
	return v
}
func getHeight() int {
	var e int
	for {
		fmt.Scanf("%d", &e)
		if e <= 10 && e >= 1 {
			return e
		}
	}
}

func move(s1, s3, s2 *stack, n int) {
	fmt.Printf(" s1 is : %v \n", s1)
	fmt.Printf(" s2 is : %v \n", s2)
	fmt.Printf(" s3 is : %v \n\n\n", s3)
	if n == 1 {
		disk := s1.pop()
		s3.push(disk)
		return
	}
	if n == 2 {
		disk := s1.pop()
		s2.push(disk)
		disk = s1.pop()
		s3.push(disk)
		disk = s2.pop()
		s3.push(disk)
	}
	if n > 2 {
		move(s1, s2, s3, n-1)
		move(s1, s3, s2, 1)
		move(s2, s3, s1, n-1)
	}

}
