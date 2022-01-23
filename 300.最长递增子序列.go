/*
 * @lc app=leetcode.cn id=300 lang=golang
 *
 * [300] 最长递增子序列
 */

// @lc code=start

func max(a, b int) int {
	if a < b {
		return b
	}
	return a
}

func lengthOfLIS2(nums []int) int {
	sz := len(nums)
	if sz == 0 {
		return 0
	}
	var dp = make([]int, sz)
	for i := 0; i < sz; i++ {
		dp[i] = 1
	}
	for i := 0; i < sz; i++ {
		for j := 0; j < i; j++ {
			if nums[j] < nums[i] {
				dp[i] = max(dp[i], dp[j] + 1)
			}
		}
	}
	var res = 0
	for _, i := range dp {
		res = max(res, i)
	}
	return res
}

// 二分
func lengthOfLIS(nums []int) int {
	sz := len(nums)
	if sz == 0 {
		return 0
	}
	var dp = make([]int, sz)
	piles := 0
	for i := 0; i < sz; i++ {
		cur:= nums[i]
		l,r:=0,piles
		for l<r {
			mid:= l + ((r-l) >>1)
			if dp[mid] >= cur {
				r = mid
			} else if(dp[mid] < cur) {
				l = mid +1
			}
		}
		if l == piles {
			piles++
		}
		dp[l] = cur
	}
	return piles
}
// @lc code=end

