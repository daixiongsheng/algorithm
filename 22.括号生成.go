/*
 * @lc app=leetcode.cn id=22 lang=golang
 *
 * [22] 括号生成
 */

// @lc code=start


func generateParenthesis(n int) []string {
	if n == 1 {
		return []string{"()"}
	}
	var ret []string
	for _, s := range generateParenthesis(n - 1) {
		for i, _ := range s {
			ret = append(ret, s[0:i]+"()"+s[i:])
		}
	}
	var m = map[string]struct{}{}
	var f []string
	for _, r := range ret {
		if _, ok := m[r]; !ok {
			m[r] = struct{}{}
			f = append(f, r)
		}
	}
	return f
}
// @lc code=end

