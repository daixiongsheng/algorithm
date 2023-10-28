/*
 * @lc app=leetcode.cn id=5 lang=golang
 *
 * [5] 最长回文子串
 */

// @lc code=start
func longestPalindrome(s string) string {
	l := len(s)
	if l < 2 {
		return s
	}
	dp := make([][]bool, l)
	for i := 0; i < l; i++ {
		dp[i] = make([]bool, l)
	}
	for i := 0; i < l; i++ {
		dp[i][i] = true
	}
	maxLen, begin := 1, 0
	for i := 2; i <= l; i++ {
		for start := 0; start < l; start++ {
			end := i + start - 1
			if end >= l {
				break
			}
			if s[start] == s[end] {
				if end-start < 3 {
					dp[start][end] = true
				} else {
					dp[start][end] = dp[start+1][end-1]
				}
			} else {
				dp[start][end] = false
			}

			if dp[start][end] && end-start+1 > maxLen {
				maxLen = end - start + 1
				begin = start
			}
		}
	}

	return s[begin : begin+maxLen]
}

// @lc code=end
