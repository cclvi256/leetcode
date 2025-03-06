package main

import "sort"

func groupAnagrams(strs []string) [][]string {
	hash_map := make(map[string][]string)

	for _, word := range strs {
		hash_key := word_sort(word)

		hash_map[hash_key] = append(hash_map[hash_key], word)
	}

	result := make([][]string, 0, len(hash_map))
	for _, v := range hash_map {
		result = append(result, v)
	}

	return result
}

func word_sort(s string) string {
	r := []rune(s)
	sort.Slice(r, func(i, j int) bool { return r[i] < r[j] })
	return string(r)
}

func _() {
	strs := []string{"eat", "tea", "tan", "ate", "nat", "bat"}
	result := groupAnagrams(strs)
	println(result)
}
