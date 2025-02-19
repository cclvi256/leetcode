package main

func trap(height []int) int {
	left, right := 0, len(height)-1

	max_left, max_right := height[left], height[right]
	result := 0

	for left < right {
		if max_left < max_right {
			left++
			max_left = max(max_left, height[left])
			possible_water_level := min(max_left, max_right)
			if height[left] < possible_water_level {
				result += possible_water_level - height[left]
			}
		} else {
			right--
			max_right = max(max_right, height[right])
			possible_water_level := min(max_left, max_right)
			if height[right] < possible_water_level {
				result += possible_water_level - height[right]
			}
		}
	}

	return result
}

func _() {
	println(trap([]int{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1})) // 6
}
