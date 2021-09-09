/*
 * @lc app=leetcode.cn id=46 lang=javascript
 *
 * [46] 全排列
 */

// @lc code=start
/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var permute = function (nums2) {
	const arr = []
	function fn(nums, ret = []) {
		if (ret.length === nums2.length) {
			arr.push([...ret])
		}
		for (const n in nums) {
			ret.push(nums[n])
			const tp = [...nums]
			tp.splice(n, 1)
			fn(tp, ret)
			ret.pop()
		}
	}
	fn(nums2)
	return arr
}
// @lc code=end

