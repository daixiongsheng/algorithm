/*
 * @lc app=leetcode.cn id=188 lang=golang
 *
 * [188] 买卖股票的最佳时机 IV
 */

// @lc code=start
func maxProfit(k int, prices []int) int {
	var max func(...int) int
	max = func(reset ...int) int {
		m := reset[0]
		for _, v := range reset {
			if m < v {
				m = v
			}
		}
		return m
	}
	n := len(prices)
	dp := make([][]int, n+1)
	for i := range dp {
		dp[i] = make([]int, 2)
	}
	// dp[2][3][0] 的含义：
	// 今天是第⼆天，我现在⼿上没有持有股票，⾄今最多进⾏3次交易。
	dp[0][1] = -prices[0]
	for i := 1; i < n; i++ {
		dp[i][0] = max(dp[i-1][0], dp[i-1][1]+prices[i])
		dp[i][1] = max(dp[i-1][1], -prices[i])
	}
	return dp[n-1][0]
}

// @lc code=end

