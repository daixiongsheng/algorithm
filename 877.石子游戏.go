/*
 * @lc app=leetcode.cn id=877 lang=golang
 *
 * [877] 石子游戏
 */
package main

func main() {
	print(stoneGame([]int{5, 3, 4, 5}))
}

// @lc code=start
func stoneGame(piles []int) bool {
	size := len(piles)
	dp := make([][][2]int, size+1)
	for i := 0; i <= size; i++ {
		dp[i] = make([][2]int, size+1)
	}
	for i := 0; i < size; i++ {
		dp[i][i][0] = piles[i]
	}

	for i := 2; i <= size; i++ {
		for j := 0; j <= size-i; j++ {
			k := i + j - 1
			left, right := piles[j]+dp[j+1][k][1], piles[k]+dp[j][k-1][1]
			if left > right {
				dp[j][k][0] = left
				dp[j][k][1] = dp[j+1][k][0]
			} else {
				dp[j][k][0] = right
				dp[j][k][1] = dp[j][k-1][0]
			}
		}
	}
	return dp[0][size-1][0]-dp[0][size-1][1] > 0
}

// @lc code=end
