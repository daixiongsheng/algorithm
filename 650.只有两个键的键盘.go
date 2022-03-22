/*
 * @lc app=leetcode.cn id=650 lang=golang
 *
 * [650] 只有两个键的键盘
 */
package main

import "math"

// @lc code=start
func minSteps(n int) int {
	var min func(...int) int
	min = func(res ...int) int {
		m := res[0]
		for _, v := range res {
			if m > v {
				m = v
			}
		}
		return m
	}
	dp := make([]int, n+1)
	for i := 2; i <= n; i++ {
		dp[i] = math.MaxInt32
		for j := 1; j*j <= i; j++ {
			if i%j == 0 {
				dp[i] = min(dp[i], dp[i/j]+j, dp[j]+i/j)
			}
		}
	}

	return dp[n]
}

// @lc code=end
