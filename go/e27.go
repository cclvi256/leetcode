package main

func removeElement(nums []int, val int) int {
	i := 0
	for j := 0; j < len(nums); j++ {
		if nums[j] != val {
			nums[i] = nums[j]
			i++
		}
	}
	return i
}

func _() {
	removeElement([]int{3, 2, 2, 3}, 3)
	removeElement([]int{0, 1, 2, 2, 3, 0, 4, 2}, 2)
}
