/*
 * @lc app=leetcode.cn id=283 lang=golang
 *
 * [283] 移动零
 */

// @lc code=start
func moveZeroes(nums []int) []int {
	i, j := 0, 0
	n := len(nums)
	for j < n && i < n {
		if nums[i] == 0 {
			j=i
			for j < n && nums[j] == 0 {
				j++
			}
			if j >= n {
				break
			}
			nums[i] = nums[j]
			nums[j] = 0
			i++
			j++
		} else {
			i++
		}
	}
	return nums
}
// @lc code=end

