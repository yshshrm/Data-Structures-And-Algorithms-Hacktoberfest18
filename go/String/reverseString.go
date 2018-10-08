package main

func reverseString(str string) string {
	runed := []rune(str)
	for i, j := 0, len(runed)-1; i < len(runed)/2; i, j = i+1, j-1 {
		runed[i], runed[j] = runed[j], runed[i]
	}
	return string(runed)
}

func main() {
	print(reverseString("reverse me"))
}
