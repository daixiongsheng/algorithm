/*
 * @lc app=leetcode.cn id=53 lang=golang
 *
 * [53] 最大子序和
 */

// @lc code=start

func maxSubArray(nums []int) int {
	size := len(nums)
	if size == 0 {
		return 0
	}
	var max = func(a, b int) int {
		if a > b {
			return a
		}
		return b
	}
	preM := 0
	m := nums[0]

	for i := 0; i < size; i++ {
		preM = max(preM+nums[i], nums[i])
		m = max(preM, m)
	}
	return m
}
// @lc code=end

