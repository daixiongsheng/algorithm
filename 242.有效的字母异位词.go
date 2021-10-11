/*
 * @lc app=leetcode.cn id=242 lang=golang
 *
 * [242] 有效的字母异位词
 */

// @lc code=start

func isAnagram(s string, t string) bool {
	m:= map[int32]int{}
	for _, c := range s {
		m[c]++
	}

	for _, c := range t {
		m[c]--
	}

	for _, v := range m {
		if v != 0 {
			return false
		}
	}
	return true
}
// @lc code=end

