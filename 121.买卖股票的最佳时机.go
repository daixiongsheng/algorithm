/*
 * @lc app=leetcode.cn id=121 lang=golang
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
func maxProfit(prices []int) int {
	n := len(prices)
	if n <= 1 {
		return 0
	}
	minPrice := math.MaxInt32
	maxPrice := 0
	for i := 0; i < n; i++ {
		if prices[i] < minPrice {
			minPrice = prices[i]
		} else if prices[i]-minPrice > maxPrice {
			maxPrice = prices[i] - minPrice
		}
	}
	return maxPrice
}

// @lc code=end
