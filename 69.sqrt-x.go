/*
 * @lc app=leetcode.cn id=69 lang=golang
 *
 * [69] Sqrt(x)
 */

// @lc code=start
// 简单二分
func mySqrt(x int) int {
	l, h := 0.0, float64(x)
	f := float64(x)
	var mid float64
	for l < h {
		mid = l + (h-l)/2.0
		result := mid * mid
		if int(result) == x {
			return int(mid)
		} else if result > f {
			h = mid
		} else {
			l = mid
		}
	}
	return int(mid)
}
// @lc code=end

