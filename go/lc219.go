package leetcode

func containsNearbyDuplicate(nums []int, k int) bool {
	if len(nums) <= 1 {
		return false
	}

	set := make(map[int]int)

	for index, value := range nums {
		if i, ok := set[value]; ok && index-i <= k {
			return true
		}
		set[value] = index
	}

	return false
}
