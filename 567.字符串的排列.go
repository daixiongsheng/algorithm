/*
 * @lc app=leetcode.cn id=567 lang=golang
 *
 * [567] 字符串的排列
 */

// @lc code=start

func checkInclusion(t string, s string) bool {
	window, need := map[uint8]int{}, map[uint8]int{}
	for _, v := range t {
		need[uint8(v)]++
	}
	left, right, valid := 0, 0, 0
	lens, lent := len(s), len(t)
	for right < lens {
		c := s[right]
		right++
		if _, ok := need[c]; ok {
			window[c]++
			if window[c] == need[c] {
				valid += window[c]
			}
		}
		for right-left >= lent {
			if valid == lent {
				return true
			}
			d := s[left]
			left++
			if _, ok := need[d]; ok {
				if window[d] == need[d] {
					valid -= window[d]
				}
				window[d]--
			}
		}
	}
	return false
}
// @lc code=end

