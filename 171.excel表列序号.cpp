/*
 * @lc app=leetcode.cn id=171 lang=cpp
 *
 * [171] Excel表列序号
 */

// @lc code=start
class Solution {
public:
    int titleToNumber(string s) {
        int sum = 0;
        for (char ch : s){
            sum = sum * 26 + (ch - 'A' + 1);
        }
        return sum;
    }
};
// @lc code=end

