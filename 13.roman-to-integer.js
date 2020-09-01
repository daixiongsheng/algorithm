/*
 * @lc app=leetcode id=13 lang=javascript
 *
 * [13] Roman to Integer
 */
// @lc code=start
/**
 * @param {string} s
 * @return {number}
 */
var romanToInt = function(s) {

    const romanValue = {
        I: 1,
        V: 5,
        X: 10,
        L: 50,
        C: 100,
        D: 500,
        M: 1000
    }
    const arr = s.split('').map(item => {
        return romanValue[item]
    })
    let sum = 0
    let i
    for (i = 0; i < arr.length; i++) {
        if (arr[i] < arr[i + 1] && i < arr.length - 1) {
            sum += arr[i + 1] - arr[i]
            i++
        } else {
            sum += arr[i]
        }
    }
    return sum
};
// @lc code=end

// const assert = require('assert')
// assert.strictEqual(romanToInt('III'), 3)
// assert.strictEqual(romanToInt('IV'), 4)
// assert.strictEqual(romanToInt('IX'), 9)
// assert.strictEqual(romanToInt('LVIII'), 58)
// assert.strictEqual(romanToInt('MCMXCIV'), 1994)