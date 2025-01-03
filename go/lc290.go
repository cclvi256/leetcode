package main

import "strings"

func wordPattern(pattern string, s string) bool {
	words := strings.Split(s, " ")

	if len(pattern) != len(words) {
		return false
	}

	forward_map := make(map[byte]string)
	reverse_map := make(map[string]byte)

	for index, letter := range pattern {
		if mapped_word, found := forward_map[byte(letter)]; found {
			if mapped_word != words[index] {
				return false
			}
		} else {
			forward_map[byte(letter)] = words[index]
		}

		if mapped_letter, found := reverse_map[words[index]]; found {
			if mapped_letter != byte(letter) {
				return false
			}
		} else {
			reverse_map[words[index]] = byte(letter)
		}
	}

	return true
}

func lc290_run() {

}
