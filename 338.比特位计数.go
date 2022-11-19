/*
 * @lc app=leetcode.cn id=338 lang=golang
 *
 * [338] 比特位计数
 */

// @lc code=start
func countBits(n int) []int {
	r := make([]int, n+1)
	r[0] = 0
	for i := 1; i <= n; i++ {
		f := 0
		this := i
		for this > 0 {
			f += this & 1
			this >>= 1
		}
		r[i] = f
	}
	return r
}

// @lc code=end

