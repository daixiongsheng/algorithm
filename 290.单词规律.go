/*
 * @lc app=leetcode.cn id=290 lang=golang
 *
 * [290] 单词规律
 */

// @lc code=start

type Value struct {
	v string
	k int32
}

func wordPattern(pattern string, s string) bool {
	m := map[string]*Value{}
	words := strings.Split(s, " ")
	if len(pattern) != len(words) {
		return false
	}
	for i, c := range pattern {
		if m[words[i]] != nil && (m[words[i]].v != words[i] || m[words[i]].k != c) {
			return false
		}
		m[words[i]] = &Value{
			words[i],
			c,
		}
	}
	m2 := map[int32]*Value{}
	for i, c := range pattern {
		if m2[c] != nil && (m2[c].v != words[i] || m2[c].k != c) {
			return false
		}
		m2[c] = &Value{
			words[i],
			c,
		}
	}
	return true
}
// @lc code=end

