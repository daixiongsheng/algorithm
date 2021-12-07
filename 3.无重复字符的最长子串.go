/*
 * @lc app=leetcode.cn id=3 lang=golang
 *
 * [3] 无重复字符的最长子串
 */
// @lc code=start

func lengthOfLongestSubstring2(s string) int {
	i, j, size := 0, 1, len(s)
	if size == 0 {
		return 0
	}
	if size == 1 {
		return 1
	}
	m := 0
	mp := map[uint8]bool{}
	var max = func(a, b int) int {
		if a < b {
			return b
		}
		return a
	}
	for i < size {
		mp[s[i]] = true
		if i == j {
			j++
		}
		for j < size {
			if !mp[s[j]] {
				mp[s[j]] = true
				j++
			} else {
				m = max(m, j - i)
				break
			}
		}
		if j == size {
			break
		}
		delete(mp, s[i])
		i++
	}
	return max(m, j - i)
}


func lengthOfLongestSubstring(s string) int {
	window := map[uint8]int{}
	var ret int
	left, right := 0, 0
	var max = func(a, b int) int {
		if a < b {
			return b
		}
		return a
	}
	lens := len(s)
	for right < lens {
		c := s[right]
		right++
		window[c]++
		for window[c] > 1 {
			d := s[left]
			left++
			window[d]--
		}
		ret = max(ret, right-left)
	}
	return ret
}
// @lc code=end

