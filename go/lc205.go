package main

func isIsomorphic(s string, t string) bool {
	return unidirectional_isomprphic(s, t) && unidirectional_isomprphic(t, s)
}

func unidirectional_isomprphic(s string, t string) bool {
	letter_map := make(map[byte]byte)

	for index, letter := range s {
		if mapped_letter, found := letter_map[byte(letter)]; found {
			if mapped_letter != t[index] {
				return false
			}
		} else {
			letter_map[byte(letter)] = t[index]
		}
	}

	return true
}

func lc205_run() {

}
