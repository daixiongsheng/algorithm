/*
 * @lc app=leetcode.cn id=1185 lang=javascript
 *
 * [1185] 一周中的第几天
 */

// @lc code=start
/**
 * @param {number} day
 * @param {number} month
 * @param {number} year
 * @return {string}
 */
var dayOfTheWeek = function(day, month, year) {
    // 基姆拉尔森计算公式
    const arr = [
        'Sunday',
        'Monday',
        'Tuesday',
        'Wednesday',
        'Thursday',
        'Friday',
        'Saturday',
    ]
    if (month < 3) {
        month += 12
        --year
    }
    // w 为 0-6
    const w =
        ((day +
            2 * month +
            (3 * (month + 1)) / 5 +
            year +
            ((year / 4) >>> 0) -
            ((year / 100) >>> 0) +
            ((year / 400) >>> 0) +
            1) >>>
            0) %
        7
    return arr[w]
};
// @lc code=end

