package main

import (
	"fmt"
	"os"
	"strconv"
)

func maxInt(a []int) (m int) {
	if (len(a) == 0) {
		m = a[0]
	}
	for i := 0; i < len(a); i++ {
		if (a[i] > m) {
			m = a[i]
		}
	}
	return
}

func sort(input []int) (output []int) {
	counts := make([]int, maxInt(input) + 1)
	for i := 0; i < len(input); i++ {
		counts[input[i]]++
	}
	for i := 0; i < len(counts); i++ {
		for j := 0; j < counts[i]; j++ {
			output = append(output, i)
		}
	}
	return output
}

func main() {
	args := os.Args[1:]
	var input []int
	for i := 0; i < len(args); i++ {
		if num, err := strconv.Atoi(args[i]); err == nil {
			input = append(input, num)
		}
	}
	output := sort(input)
	for i := 0; i < len(output); i++ {
		fmt.Printf("%d ", output[i])
	}
	fmt.Printf("\n")
}
