/*
 * @lc app=leetcode.cn id=516 lang=golang
 *
 * [516] 最长回文子序列
 */
package main

// func main() {
// 	longestPalindromeSubseq("bbbab")
// }

// @lc code=start
func longestPalindromeSubseq(s string) int {
	var max func(int, int) int
	max = func(l1, l2 int) int {
		if l1 > l2 {
			return l1
		}
		return l2
	}
	var dp [][]int
	l1 := len(s)
	dp = make([][]int, l1+1)
	for i := range dp {
		dp[i] = make([]int, l1+1)
		// dp[i][1] = 1
	}
	for i := 0; i <= l1; i++ {
		dp[i][i] = 1
	}
	for i := l1 - 1; i >= 0; i-- {
		for j := i + 1; j < l1; j++ {
			if s[i] == s[j] {
				dp[i][j] = 2 + dp[i+1][j-1]
			} else {
				dp[i][j] = max(dp[i+1][j], dp[i][j-1])
			}
		}
	}
	return dp[0][l1-1]
}

// @lc code=end
