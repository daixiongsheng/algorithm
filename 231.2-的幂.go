/*
 * @lc app=leetcode.cn id=231 lang=golang
 *
 * [231] 2 的幂
 */

// @lc code=start
func isPowerOfTwo(n int) bool {
	if n == 1 {
		return true
	}
	if n == 0 {
		return false
	}
	f := float64(n)
	for {
		r:=f
		f = f / 2.0
		if f == 1 {
			return true
		}
		if f != float64(int(r) / 2) {
			return false
		}
	}
}
// @lc code=end

