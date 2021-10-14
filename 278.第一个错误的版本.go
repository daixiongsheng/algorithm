/*
 * @lc app=leetcode.cn id=278 lang=golang
 *
 * [278] 第一个错误的版本
 */

// @lc code=start
/**
 * Forward declaration of isBadVersion API.
 * @param   version   your guess about first bad version
 * @return 	 	      true if current version is bad
 *			          false if current version is good
 * func isBadVersion(version int) bool;
 */

func firstBadVersion(n int) int {
		l := 1
		var mid = n
		for l <= n {
			mid =  l + (n  - l) >> 1
			if (isBadVersion(mid)) {
				if (isBadVersion(mid - 1)) {
					n = mid - 1
				} else {
					return mid
				}
			} else  {
				l = mid + 1
			}
		}
		return mid
}
// @lc code=end

