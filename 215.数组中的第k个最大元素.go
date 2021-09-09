/*
 * @lc app=leetcode.cn id=215 lang=golang
 *
 * [215] 数组中的第K个最大元素
 */

// @lc code=start
func findKthLargest(nums []int, k int) int {
	size, low := len(nums), 0
	high := size - 1

	swap := func(nums []int, low, high int) {
		tp := nums[low]
		nums[low] = nums[high]
		nums[high] = tp
	}

	partition := func(nums []int, low , high int) int {
		p := nums[low]
		j := low
		for i:= low + 1; i <= high;i++ {
			if nums[i] > p {
				j++
				swap(nums, j ,i)
			}
		}
		swap(nums, j ,low)
		return j
	}
	for {
		index := partition(nums, low, high)
		if index == k - 1 {
			return nums[index]
		} else if index < k - 1 {
			low = index + 1
		} else {
			high = index - 1
		}
	}
}
// @lc code=end

