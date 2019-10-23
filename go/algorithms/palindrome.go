package main

import "fmt"

func isPalindrome(input string) bool {
	var x = len(input)
	for i := 0; i < x/2; i++ {
		if input[i] != input[len(input)-i-1] {
			return false
		}
	}
	return true
}

func main() {
	if isPalindrome("ARARA") {
		fmt.Println("Is a palindrome")
	}
}

