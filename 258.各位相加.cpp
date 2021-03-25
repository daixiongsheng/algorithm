/*
 * @lc app=leetcode.cn id=258 lang=cpp
 *
 * [258] 各位相加
 */

// @lc code=start
class Solution {
public:
    int addDigits(int num) {
        if(!num) return 0;
        const int n = num % 9;
        return n == 9 ? 0 : n == 0 ? 9 : n;
    }
};
// @lc code=end

