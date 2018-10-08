package main

import "fmt"

func isPalindrome(str string) bool {
	for i := 0; i < len(str)/2; i++ {
		if str[i] != str[len(str)-i-1] {
			return false
		}
	}
	return true
}

func main() {
	fmt.Println(isPalindrome("I am not a palindrome"))
	fmt.Println(isPalindrome("otto"))
}
