/*
 * @lc app=leetcode.cn id=1283 lang=golang
 *
 * [1283] 使结果不超过阈值的最小除数
 */

package main

func main() {
	var nums = []int {21212,10101,12121}
	smallestDivisor(nums, 1000000)
}
// @lc code=start
func smallestDivisor(nums []int, threshold int) int {
	sum, result, max:= 0, (1 << 31) - 1, (-1 << 32)
	for _, v := range nums {
		if max < v {
			max = v
		}
	}
	i := 1
	l, h := 1, max
	for i <= result && l <= h {
		i = l + ((h - l) >> 1)
		sum = 0
		getSum(nums, &sum, i)
		if sum <= threshold {
			result = i
			h = i - 1
		} else {
			l = i + 1
		}
	}
	return result
}

func getSum(nums []int, sum *int, i int) {
	for _, v := range nums {
		*sum += (v - 1) / i + 1
		//if v == v / i * i {
		//	*sum += m
		//} else {
		//	*sum += m + 1
		//}
	}
}
// @lc code=end

