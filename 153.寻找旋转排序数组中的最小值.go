/*
 * @lc app=leetcode.cn id=153 lang=golang
 *
 * [153] 寻找旋转排序数组中的最小值
 */

// @lc code=start

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
func findMin(nums []int) int {
	var mid int
	l, h := 0, len(nums)-1
	for l < h {
		mid = l + (h-l)>>1
		// mid 到h一定是增序
		if nums[mid] < nums[h] {
			h = mid
		} else {
			l = mid + 1
		}
	}
	return nums[l]
}

// @lc code=end

