/*
 * @lc app=leetcode.cn id=268 lang=golang
 *
 * [268] 丢失的数字
 */

// @lc code=start
func missingNumber(nums []int) int {
	n := len(nums)
	sn := n * (n + 1) / 2
	for _, i := range nums {
		sn -= i
	}
	return sn
}
// @lc code=end

