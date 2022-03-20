/*
 * @lc app=leetcode.cn id=1143 lang=golang
 *
 * [1143] 最长公共子序列
 */
package main

func main() {
	longestCommonSubsequence("abcde", "ace")
}

// @lc code=start
func longestCommonSubsequence2(text1 string, text2 string) int {
	var dp, max func(int, int) int
	max = func(l1, l2 int) int {
		if l1 > l2 {
			return l1
		}
		return l2
	}
	dp = func(l1, l2 int) int {
		if l1 == -1 || l2 == -1 {
			return 0
		}
		if text1[l1] == text2[l2] {
			return dp(l1-1, l2-1) + 1
		}
		return max(
			dp(l1-1, l2),
			dp(l1, l2-1),
		)
	}
	return dp(len(text1)-1, len(text2)-1)
}

func longestCommonSubsequence(text1 string, text2 string) int {
	var max func(int, int) int
	max = func(l1, l2 int) int {
		if l1 > l2 {
			return l1
		}
		return l2
	}
	var dp [][]int
	l1, l2 := len(text1), len(text2)
	dp = make([][]int, l1+1)
	for i := range dp {
		dp[i] = make([]int, l2+1)
		// dp[i][1] = 1
	}
	for i := 1; i <= l2; i++ {
		// dp[1][i] = 1
	}
	for i := 1; i <= l1; i++ {
		for j := 1; j <= l2; j++ {
			if text1[i-1] == text2[j-1] {
				dp[i][j] = 1 + dp[i-1][j-1]
			} else {
				dp[i][j] = max(dp[i][j-1], dp[i-1][j])
			}
		}
	}
	return dp[l1][l2]
}

// @lc code=end
