/*
 * @lc app=leetcode.cn id=72 lang=golang
 *
 * [72] 编辑距离
 */
package main

// @lc code=start
func minDistance(word1 string, word2 string) int {

	var min func(a ...int) int
	min = func(a ...int) int {
		m := a[0]
		for _, i := range a {
			if m > i {
				m = i
			}
		}
		return m
	}
	l1, l2 := len(word1), len(word2)
	// 存储 s1[0..i]和s2[0..j] 的最小编辑距离
	dp := make([][]int, l1+1)
	for i := range dp {
		dp[i] = make([]int, l2+1)
		dp[i][0] = i
	}
	for i := range dp[0] {
		dp[0][i] = i
	}
	dp[0][0] = 0
	for i := 1; i <= l1; i++ {
		for j := 1; j <= l2; j++ {
			if word1[i-1] == word2[j-1] {
				// 相等跳过
				dp[i][j] = dp[i-1][j-1]
			} else {
				// 不等看哪种选择最短，删，增，改
				dp[i][j] = 1 + min(
					dp[i-1][j-1],
					dp[i-1][j],
					dp[i][j-1],
				)
			}
		}
	}
	return dp[l1][l2]
}

// func main() {
// 	fmt.Println(minDistance("horse", "ros"))
// }

// @lc code=end
