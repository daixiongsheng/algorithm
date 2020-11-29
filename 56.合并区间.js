/*
 * @lc app=leetcode.cn id=56 lang=javascript
 *
 * [56] 合并区间
 */

// @lc code=start
/**
 * @param {number[][]} intervals
 * @return {number[][]} 返回结果只需要包含对应的值就行，不需要排序
 */
var merge = function (intervals, result = []) {
    for (const interval of intervals.sort((a, b) => a[0] - b[0])){
        if (result[0] && interval[0] <= result[0][1]) {
            result[0][1] = Math.max(result[0][1], interval[1])
        }
        else {
            result.unshift(interval);
        }
    }
    return result
}
// @lc code=end

