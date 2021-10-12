/*
 * @lc app=leetcode.cn id=9 lang=golang
 *
 * [9] 回文数
 */
 import (
	"strconv"
)
// @lc code=start
func isPalindrome(x int) bool {
	s :=strconv.Itoa(x)
	i := len(s) - 1
	j := 0
	for j < i {
		if s[i] != s[j] {
			return false
		}
		i--
		j++
	}
	return true
}
// @lc code=end

