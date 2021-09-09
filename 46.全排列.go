/*
 * @lc app=leetcode.cn id=46 lang=golang
 *
 * [46] 全排列
 */

// @lc code=start
func permute(nums []int) [][]int {
	size := len(nums)
	arr := make([][]int, 0)
	r := make([]int, 0)
	used := make([]bool, size)
	var fn func(nums []int, ret []int)
	fn = func(nums []int, ret []int) {
		if len(ret) == size {
			r := make([]int, size)
			copy(r, ret)
			arr = append(arr, r)
		}
		for i, num := range nums {
			if !used[i] {
				used[i] = true
				ret = append(ret, num)
				fn(nums, ret)
				ret = ret[:len(ret)-1]
				used[i] = false
			}
		}
	}
	fn(nums, r)
	return arr
}
// @lc code=end

