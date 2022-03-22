/*
 * @lc app=leetcode.cn id=10 lang=golang
 *
 * [10] 正则表达式匹配
 */

// @lc code=start
func isMatch(s string, p string) bool {
	m := map[string]bool{}
	var dp func(int, int) bool
	dp = func(i, j int) bool {
		key := strconv.Itoa(i) + "-" + strconv.Itoa(j)
		if ok := m[key]; ok {
			return m[key]
		}
		if j == len(p) {
			return i == len(s)
		}
		var ans bool
		first := i < len(s) && (p[j] == s[i] || p[j] == '.')
		if j <= len(p)-2 && p[j+1] == '*' {
			ans = dp(i, j+2) || (first && dp(i+1, j))
		} else {
			ans = first && dp(i+1, j+1)
		}
		m[key] = ans
		return ans
	}
	return dp(0, 0)
}

// @lc code=end
