/*
 * @lc app=leetcode.cn id=33 lang=golang
 *
 * [33] 搜索旋转排序数组
 */

// @lc code=start
func search(nums []int, target int) int {
	left, right := 0, len(nums) - 1
	n := right
	var mid int
	for left <= right {
		mid = left + (right - left) >> 1
		if nums[mid] == target {
			return mid
		} else if nums[0] > nums[mid] {
			if nums[mid] < target && nums[n] >= target {
				left = mid + 1
			} else {
				right = mid - 1
			}
		} else if nums[0] <= nums[mid] {
			if nums[0] <= target && nums[mid] > target {
				right = mid - 1
			} else {
				left = mid + 1
			}
		}
	}
	return -1
}
// @lc code=end

