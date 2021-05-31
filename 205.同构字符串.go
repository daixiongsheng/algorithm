/*
 * @lc app=leetcode.cn id=205 lang=golang
 *
 * [205] 同构字符串
 */
// package main

// import (
// 	"fmt"
// )

// func main()  {
// 	fmt.Println(isIsomorphic("babc", "bada"))
// }
// @lc code=start
func isIsomorphic(s string, t string) bool {
	return f(s,t) && f(t,s)
}
func f(s string, t string) bool {
	mp := make(map[uint8]uint8)
	var i int
	for i = len(s) - 1; i >= 0; i-- {
		if mp[s[i]] != 0 {
			if mp[s[i]] != t[i] {
				return false
			}
		} else {
			if mp[s[i]] != 0 {
				return false
			}
			mp[s[i]] = t[i]
		}
	}
	return true
}
// @lc code=end

