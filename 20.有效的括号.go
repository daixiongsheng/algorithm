/*
 * @lc app=leetcode.cn id=20 lang=golang
 *
 * [20] 有效的括号
 */

// @lc code=start
func isValid(s string) bool {
	m := map[int32]int32{}
	stack := make([]int32, len(s))
	m['('] = ')'
	m[')'] = '('
	m['['] = ']'
	m[']'] = '['
	m['{'] = '}'
	m['}'] = '{'
	i := -1
	for _, c := range s {
		switch c {
		case ']':
			fallthrough
		case '}':
			fallthrough
		case ')':
			if i >= 0 && stack[i] == m[c] {
				i--
			} else {
				return false
			}
		default:
			i++
			stack[i] = c
		}
	}
	return i == -1
}
// @lc code=end

