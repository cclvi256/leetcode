package main

func longestConsecutive(nums []int) int {
	numSet := make(map[int]bool)

	for _, num := range nums {
		numSet[num] = true
	}

	streak := 0

	for num := range numSet {
		if !numSet[num-1] {
			current := num
			currentStreak := 1

			for numSet[current+1] {
				current++
				currentStreak++
			}

			if streak < currentStreak {
				streak = currentStreak
			}
		}
	}

	return streak
}
