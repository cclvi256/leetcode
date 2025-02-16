package main

func isSubsequence(s string, t string) bool {
	i, j := 0, 0
	for i < len(s) && j < len(t) {
		if s[i] == t[j] {
			i++
		}
		j++
	}
	return i == len(s)
}

func _() {
	println(isSubsequence("abc", "ahbgdc")) // true
	println(isSubsequence("axc", "ahbgdc")) // false
}
