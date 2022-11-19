/*
 * @lc app=leetcode.cn id=303 lang=golang
 *
 * [303] 区域和检索 - 数组不可变
 */

// @lc code=start
// package algorithm

type NumArray struct {
	data []int
	sum  []int
}

func Constructor(nums []int) NumArray {
	r := NumArray{}
	n := len(nums)
	r.data = make([]int, n)
	r.sum = make([]int, n)
	for i := 0; i < n; i++ {
		r.data[i] = nums[i]
		if i == 0 {
			r.sum[i] = nums[i]
		} else {
			r.sum[i] = nums[i] + r.sum[i-1]
		}
	}
	return r
}

func (this *NumArray) SumRange(left int, right int) int {
	return this.sum[right] - this.sum[left] + this.data[left]
}

/**
 * Your NumArray object will be instantiated and called as such:
 * obj := Constructor(nums);
 * param_1 := obj.SumRange(left,right);
 */
// @lc code=end
