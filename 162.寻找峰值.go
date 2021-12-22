/*
 * @lc app=leetcode.cn id=162 lang=golang
 *
 * [162] 寻找峰值
 */

// @lc code=start

func findPeakElement(nums []int) int {
	size := len(nums) - 1
	l, h := 0, size

	var mid int
	for l <= h {
		mid = l + (h-l)>>1
		if mid > 0 && mid <= size && nums[mid] < nums[mid-1] {
			h = mid - 1
		} else if mid >= 0 && mid < size && nums[mid] < nums[mid+1] {
			l = mid + 1
		} else {
			break
		}
	}
	return mid
}

// @lc code=end

