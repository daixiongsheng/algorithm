/*
 * @lc app=leetcode.cn id=76 lang=golang
 *
 * [76] 最小覆盖子串
 */

// @lc code=start



func minWindow(s string, t string) string {
	window, need := map[uint8]int{}, map[uint8]int{}
	for _, v := range t {
		need[uint8(v)]++
	}
	left, right, valid := 0, 0, 0
	lens, lent, start, size := len(s), len(t), 0, 1<<31-1
	for right < lens {
		c := s[right]
		right++
		if _, ok := need[c]; ok {
			window[c]++
			if window[c] <= need[c] {
				valid++
			}
		}
		for valid == lent {
			if right-left < size {
				start = left
				size = right - left
			}
			d := s[left]
			left++
			if _, ok := need[d]; ok {
				if window[d] == need[d] {
					valid--
				}
				window[d]--
			}
		}
	}
	if size == 1<<31-1 {
		return ""
	}
	return s[start : start+size]
}
// @lc code=end

