package main

import "fmt"

func twoSum(nums []int, target int) []int {
	hash_map := make(map[int]int)

	for index, value := range nums {
		target_num := target - value
		target_index, found := hash_map[target_num]

		if found {
			return []int{target_index, index}
		} else {
			hash_map[value] = index
		}
	}

	return []int{}
}

func main() {
	var array_len int;
	fmt.Printf("Enter array length: ");
	fmt.Scan(&array_len)

	nums := make([]int, array_len)

	fmt.Printf("Enter %d integers seperated by spaces: ", array_len)
	for i := 0; i < array_len; i++ {
		fmt.Scan(&nums[i])
	}

	var target int
	fmt.Printf("Enter target sum: ")
	fmt.Scan(&target)

	result := twoSum(nums, target)
	fmt.Printf("Result: %v\n", result)
}