/*
 * @lc app=leetcode.cn id=263 lang=golang
 *
 * [263] 丑数
 */

// @lc code=start
func isUgly(n int) bool {
	if n <= 0 {
		return false
	}
	var mod int
	for n > 1 {
		mod = n % 5
		if mod == 0 {
			n /= 5
			continue
		}
		mod = n % 3
		if mod == 0 {
			n /= 3
			continue
		}
		mod = n % 2
		if mod == 0 {
			n >>= 1
			continue
		}
		return false
	}
	return true
}
// @lc code=end

