package leetcode

func isHappy(n int) bool {
	set := make(map[int]bool)

	for n != 1 {
		if set[n] {
			return false
		}
		set[n] = true
		n = square_sum(separate(n))
	}

	return true
}

func separate(n int) []int {
	var res []int
	for n > 0 {
		res = append(res, n%10)
		n /= 10
	}
	return res
}

func square_sum(nums []int) int {
	var sum int
	for _, value := range nums {
		sum += value * value
	}
	return sum
}
