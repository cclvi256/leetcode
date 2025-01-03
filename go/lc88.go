package main

func merge(nums1 []int, m int, nums2 []int, n int) {
	tail1, tail2 := m-1, n-1
	tail := m + n - 1

	for tail1 >= 0 && tail2 >= 0 {
		if nums1[tail1] > nums2[tail2] {
			nums1[tail] = nums1[tail1]
			tail1--
		} else {
			nums1[tail] = nums2[tail2]
			tail2--
		}
		tail--
	}

	for tail2 >= 0 {
		nums1[tail] = nums2[tail2]
		tail2--
		tail--
	}
}

func _() {
	nums1 := []int{1, 2, 3, 0, 0, 0}
	m := 3
	nums2 := []int{2, 5, 6}
	n := 3

	merge(nums1, m, nums2, n)
	println(nums1)
}
