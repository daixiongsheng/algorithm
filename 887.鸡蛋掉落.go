/*
 * @lc app=leetcode.cn id=887 lang=golang
 *
 * [887] 鸡蛋掉落
 */
package main

import (
	"strconv"
)

// @lc code=start
func superEggDrop2(k int, n int) int {
	var max, min, dp func(a, b int) int
	max = func(a, b int) int {
		if a < b {
			return b
		}
		return a
	}
	min = func(a, b int) int {
		if a > b {
			return b
		}
		return a
	}
	dp = func(k, n int) int {
		// 只有一个鸡蛋需要n次
		if k == 1 {
			return n
		}
		// 没有楼层，不需要
		if n == 0 {
			return 0
		}
		res := n
		// 表示只有i个鸡蛋时，j楼需要最少的次数
		// dp[i][j]
		for i := 1; i <= n; i++ {
			// 1-N floor
			res = min(
				res,
				// 在第i层扔鸡蛋
				max(
					dp(k-1, i-1),
					dp(k, n-i),
				)+1,
			)
		}
		return res
	}
	return dp(k, n)
}
func superEggDrop3(k int, n int) int {
	var min, dp func(a, b int) int
	// max = func(a, b int) int {
	// 	if a < b {
	// 		return b
	// 	}
	// 	return a
	// }
	min = func(a, b int) int {
		if a > b {
			return b
		}
		return a
	}
	mp := map[string]int{}
	dp = func(k, n int) int {
		// 只有一个鸡蛋需要n次
		if k == 1 {
			return n
		}
		// 没有楼层，不需要
		if n == 0 {
			return 0
		}
		key := strconv.Itoa(k) + "-" + strconv.Itoa(n)
		if _, ok := mp[key]; ok {
			return mp[key]
		}
		res := n
		// 表示只有i个鸡蛋时，j楼需要最少的次数
		// dp[i][j]
		// for i := 1; i <= n; i++ {
		// 	// 1-N floor
		// 	res = min(
		// 		res,
		// 		// 在第i层扔鸡蛋
		// 		max(
		// 			dp(k-1, i-1),
		// 			dp(k, n-i),
		// 		)+1,
		// 	)
		// }
		// 二分
		l, h := 1, n
		for l <= h {
			mid := (l + h) / 2
			broken := dp(k-1, mid-1)
			nobBroken := dp(k, n-mid)
			if broken > nobBroken {
				h = mid - 1
				res = min(res, broken+1)
			} else {
				l = mid + 1
				res = min(res, nobBroken+1)
			}
		}
		mp[key] = res
		return res
	}
	return dp(k, n)
}

func superEggDrop4(k int, n int) int {
	dp := make([][]int, k+1)
	for i := range dp {
		dp[i] = make([]int, n+1)
		dp[i][0] = 0
		dp[i][1] = i
	}

	for i := 0; i < n; i++ {
		dp[0][i] = 0
		dp[1][i] = i
	}
	// dp[i][m]=n
	// 表示有i个鸡蛋，可以最多尝试k次，能测到的最高楼层
	m := 0
	for dp[k][m] < n {
		m++
		for i := 1; i <= k; i++ {
			dp[i][m] = 1 + dp[i][m-1] /*楼上的*/ + dp[i-1][m-1] /*楼下的*/
		}
	}
	return m
}
func superEggDrop(k int, n int) int {
	dp := make([]int, k+1)

	// dp[i][m]=n
	// 表示有i个鸡蛋，可以最多尝试k次，能测到的最高楼层
	m := 0
	for dp[k] < n {
		m++
		for i := k; i > 0; i-- {
			dp[i] = 1 + dp[i] /*楼上的*/ + dp[i-1] /*楼下的*/
		}
	}
	return m
}

// @lc code=end
