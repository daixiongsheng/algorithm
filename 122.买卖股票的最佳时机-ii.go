/*
 * @lc app=leetcode.cn id=122 lang=golang
 *
 * [122] 买卖股票的最佳时机 II
 */

// @lc code=start


func maxProfit(prices []int) int {
	size := len(prices)
	sum := 0
	has := 0
	h := false
	for i := 0; i < size-1; i++ {
		if prices[i] < prices[i+1] {
			// 今天比明天的要小
			if h {

			} else {
				has = prices[i]
				h = true
			}
		} else {
			// 明天降价
			if h {
				// 持有，先卖
				sum += prices[i] - has
				h = false
				has = 0
			}
		}
	}
	if h {
		sum += prices[size-1] - has
	}
	return sum
}

// @lc code=end

