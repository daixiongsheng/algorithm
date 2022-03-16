/*
 * @lc app=leetcode.cn id=416 lang=golang
 *
 * [416] 分割等和子集
 */
package main

// @lc code=start
func canPartition(nums []int) bool {
	sum := 0
	for _, i := range nums {
		sum += i
	}
	if sum%2 != 0 {
		return false
	}
	sum /= 2
	dp := make([]bool, sum+1)
	dp[0] = true
	for i := 0; i < len(nums); i++ {
		for j := sum; j >= 0; j-- {
			if j-nums[i] >= 0 {
				dp[j] = dp[j] || dp[j-nums[i]]
			}
		}
	}
	return dp[sum]
}

// func main() {
// 	fmt.Println(canPartition([]int{1, 5, 11, 5}))
// }

// @lc code=end
