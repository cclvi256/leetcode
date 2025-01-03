package main

import (
	"fmt"
	"strings"
)

type line struct {
	words      []string
	maxLength  int
	characters int
	wordCount  int
}

func (l *line) addWord(word string) bool {
	wordLength := len(word)
	if l.characters+l.wordCount+wordLength > l.maxLength {
		return false
	} else {
		l.words = append(l.words, word)
		l.characters += wordLength
		l.wordCount++
		return true
	}
}

func (l *line) construct() string {
	if l.wordCount == 1 {
		return l.words[0] + strings.Repeat(" ", l.maxLength-l.characters)
	} else {
		spaces := l.maxLength - l.characters
		avrSpaces := spaces / (l.wordCount - 1)
		extraSpaces := spaces % (l.wordCount - 1)

		res := ""

		for index, word := range l.words {
			if index > 0 {
				res += strings.Repeat(" ", avrSpaces)
				if index <= extraSpaces {
					res += " "
				}
			}
			res += word
		}

		return res
	}
}

func (l *line) reset() {
	l.words = nil
	l.characters = 0
	l.wordCount = 0
}

func fullJustify(words []string, maxWidth int) []string {
	l := line{maxLength: maxWidth}
	res := make([]string, 0)

	for _, word := range words {
		if !l.addWord(word) {
			res = append(res, l.construct())
			l.reset()
			l.addWord(word)
		} else {
			l.characters += len(word)
		}
	}

	if l.wordCount > 0 {
		res = append(res, l.construct())
	}

	return res
}

func main () {
	words := []string{"This", "is", "an", "example", "of", "text", "justification."}
	maxWidth := 16
	fmt.Println(fullJustify(words, maxWidth))
}
