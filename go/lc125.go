package main

import (
	"fmt"
)

func decrease(s string) string {
	res := ""

	for _, char := range s {
		if char >= 'A' && char <= 'Z' {
			res += string(char + 32)
		} else if char >= 'a' && char <= 'z' || char >= '0' && char <= '9' {
			res += string(char)
		} else {
			continue
		}
	}

	return res
}

func isPalindrome(s string) bool {
	s = decrease(s)

	if len(s) < 2 {
		return true
	}

	i, j := 0, len(s)-1
	mid := len(s) / 2

	for i < mid {
		if s[i] != s[j] {
			return false
		}
		i++
		j--
	}

	return true
}

func _() {
	res := isPalindrome("Ich war nie auf einer Akademie")
	fmt.Println(res)
}
