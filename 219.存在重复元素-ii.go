/*
 * @lc app=leetcode.cn id=219 lang=golang
 *
 * [219] 存在重复元素 II
 */

// @lc code=start

func containsNearbyDuplicate(nums []int, k int) bool {
	m := map[int]int {}
	for i, n := range nums {
		if m[n] !=0 {
			if math.Abs(float64(i+1-m[n])) <= float64(k) {
				return true
			}else {
				m[n] = i + 1
			}
		} else {
			m[n] = i + 1
		}
	}
	return false
}

// @lc code=end

