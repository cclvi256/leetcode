package main

import (
	"fmt"
)

func firstMissingPositive(nums []int) int {
	for index, num := range nums {
		if num <= 0 {
			nums[index] = len(nums) + 1
		}
	}

	for _, num := range nums {
		num = abs(num)
		if (num) <= len(nums) {
			nums[num-1] = -abs(nums[num-1])
		}
	}

	for index, num := range nums {
		if num > 0 {
			return index + 1
		}
	}

	return len(nums) + 1
}

func abs(num int) int {
	if num < 0 {
		return -num
	}
	return num
}

func main() {
	var array_len int
	fmt.Printf("Enter array length: ")
	fmt.Scan(&array_len)

	nums := make([]int, array_len)

	fmt.Printf("Enter %d integers seperated by spaces: ", array_len)
	for i := range array_len {
		fmt.Scan(&nums[i])
	}

	result := firstMissingPositive(nums)
	fmt.Printf("Result: %v\n", result)
}
