/*
 * @lc app=leetcode.cn id=15 lang=golang
 *
 * [15] 三数之和
 */

// @lc code=start


func threeSum(nums []int) [][]int {
	sort.Ints(nums)
	var ret [][]int
	size := len(nums)
	k := 0
	for ; k < size-2; k++ {
		if nums[k] > 0 {
			break
		}
		if k > 0 && nums[k] == nums[k-1] {
			continue
		}
		i, j := k+1, size-1
		for i < j {
			sum := nums[k] + nums[i] + nums[j]
			if sum == 0 {
				ret = append(ret, []int{nums[k], nums[i], nums[j]})
				j--
				for i < j && nums[j] == nums[j+1] {
					j--
				}
				i++
				for i < j && nums[i] == nums[i-1] {
					i++
				}
			} else if sum < 0 {
				i++
				for i < j && nums[i] == nums[i-1] {
					i++
				}
			} else {
				j--
				for i < j && nums[j] == nums[j+1] {
					j--
				}
			}
		}

	}
	return ret
}
// @lc code=end

