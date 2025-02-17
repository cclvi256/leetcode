package main

func maxArea(height []int) int {
	left, right := 0, len(height)-1
	max_area := 0
	for left < right {
		if height[left] < height[right] {
			max_area = max(max_area, height[left]*(right-left))
			left++
		} else {
			max_area = max(max_area, height[right]*(right-left))
			right--
		}
	}

	return max_area
}

func _() {
	println(maxArea([]int{1, 8, 6, 2, 5, 4, 8, 3, 7}))
}
