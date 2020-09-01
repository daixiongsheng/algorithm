/*
 * @lc app=leetcode.cn id=26 lang=javascript
 *
 * [26] 删除排序数组中的重复项
 */

// @lc code=start
/**
 * @param {number[]} nums
 * @return {number}
 */
var removeDuplicates = function(nums) {
    if (nums.length < 2) return nums.length;
    let j = 1,
        i = 0;
    for (; j < nums.length; j++ ){
        if (nums[i] !== nums[j]) {
            nums[++i] = nums[j];
        }
    }
    nums.length = ++i
    return i
};
// @lc code=end
