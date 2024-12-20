package leetcode

func longestConsecutive(nums []int) int {
	num_set := make(map[int]bool)

	for _, num := range nums {
		num_set[num] = true
	}

	streak := 0

	for num := range num_set {
		if !num_set[num-1] {
			current := num
			current_streak := 1

			for num_set[current+1] {
				current++
				current_streak++
			}
			
			if streak < current_streak {
				streak = current_streak
			}
		}
	}

	return streak
}
