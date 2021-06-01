/*
 * @lc app=leetcode.cn id=485 lang=golang
 *
 * [485] 最大连续 1 的个数
 */
package main

// @lc code=start
func findMaxConsecutiveOnes(nums []int) int {
	max := 0
	count := 0
	var i int
	l := len(nums)
	for i = 0; i < l; i++ {
		if nums[i] == 1 {
			count++
		} else {
			if count >= max {
				max = count
			}
			count = 0
		}
	}
	if count >= max {
		max = count
	}
	count = 0
	return max
}

// @lc code=end
