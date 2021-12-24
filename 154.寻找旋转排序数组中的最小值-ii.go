/*
 * @lc app=leetcode.cn id=154 lang=golang
 *
 * [154] 寻找旋转排序数组中的最小值 II
 */

// @lc code=start
func findMin(nums []int) int {
	var mid int
	l, h := 0, len(nums)-1
	for l < h {
		mid = l + (h-l)>>1
		if nums[mid] < nums[h] {
			h = mid
		} else if nums[mid] > nums[h] {
			l = mid + 1
		} else {
			h--
		}
	}
	return nums[l]
}

// @lc code=end

