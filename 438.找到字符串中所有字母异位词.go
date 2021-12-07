/*
 * @lc app=leetcode.cn id=438 lang=golang
 *
 * [438] 找到字符串中所有字母异位词
 */

// @lc code=start

func findAnagrams(s string, t string) []int {
	window, need := map[uint8]int{}, map[uint8]int{}
	var ret []int
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
				ret = append(ret, left)
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
	return ret
}
// @lc code=end