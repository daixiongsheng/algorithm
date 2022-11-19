/*
 * @lc app=leetcode.cn id=326 lang=golang
 *
 * [326] 3 的幂
 */

// @lc code=start
func isPowerOfThree(n int) bool {
	// if n == 3 || n == 1 {
	// 	return true
	// }
	// if n < 3 {
	// 	return false
	// }
	// r := n / 3
	// if r*3 != n {
	// 	return false
	// }
	// return isPowerOfThree(r)
	return n > 0 && 1162261467%n == 0
}

// @lc code=end

