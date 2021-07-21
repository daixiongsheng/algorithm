/*
 * @lc app=leetcode.cn id=518 lang=golang
 *
 * [518] 零钱兑换 II
 */

// @lc code=start
func change(amount int, coins []int) int {
	var arr []int = make([]int, 5001)
	arr[0] = 1
	for _, coin := range coins {
		for i := coin; i <= amount; i++ {
				arr[i] += arr[i - coin]
			}
	}
	return arr[amount]
}
// @lc code=end

