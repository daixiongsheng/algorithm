/*
 * @lc app=leetcode.cn id=322 lang=golang
 *
 * [322] 零钱兑换
 */

// @lc code=start

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func coinChange(coins []int, amount int) int {
	var dp = make([]int, amount + 1)
	for i := 0; i < amount + 1; i++ {
		dp[i] = amount + 1
	}
	dp[0] = 0
	for i := 1; i < amount + 1; i++ {
		for _, c := range coins {
			if i - c < 0 {
				continue
			}
			dp[i] = min(dp[i], dp[i - c] + 1)
		}
	}
	if dp[amount] == amount + 1 {
		return -1
	}
	return dp[amount]
}
// @lc code=end

