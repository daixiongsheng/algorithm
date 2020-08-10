/*
 * @lc app=leetcode id=4 lang=javascript
 *
 * [4] Median of Two Sorted Arrays
 */

// @lc code=start
/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number}
 */
var findMedianSortedArrays = function(nums1, nums2) {
    const result = nums1.concat(nums2)
    result.sort((a, b) => a-b)
    if (result.length === 1) return result[0]
    const m = (result.length / 2) >>> 0
    const odd = result.length % 2 === 1
    if (odd) return result[m]
    return (result[m - 1] + result[m]) / 2
};
// @lc code=end

//console.log(findMedianSortedArrays([1, 1], [2]))
//console.log(findMedianSortedArrays([1, 2], [3, 4]) === 2.5)