/*
 * @lc app=leetcode.cn id=217 lang=golang
 *
 * [217] 存在重复元素
 */

// @lc code=start
func containsDuplicate(nums []int) bool {
	m := map[int]bool {}
	for _, n := range nums {
		if m[n] {
			return true
	} else {
		m[n] = true
	}
	}
	return false
}
// @lc code=end

