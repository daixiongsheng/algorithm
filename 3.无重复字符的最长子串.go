/*
 * @lc app=leetcode.cn id=3 lang=golang
 *
 * [3] 无重复字符的最长子串
 */
// @lc code=start
func lengthOfLongestSubstring(s string) int {
	max := func (x, y int) int {
		if x < y {
		return y
	}
		return x
	}
	m := map[byte]int{}
	i, j, size, n := 0, 0, len(s), 0
	for ; i < size; i++ {
		if i!= 0 {
			delete(m, s[i-1])
		}
		for j < size && m[s[j]] == 0 {
			m[s[j]] = 1
			j++
		}
		n = max(n, j- i)
	}
	return n
}

// @lc code=end

