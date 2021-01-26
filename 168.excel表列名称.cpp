/*
 * @lc app=leetcode.cn id=168 lang=cpp
 *
 * [168] Excel表列名称
 */
// @lc code=start
class Solution {
public:
    string convertToTitle(int n) {
        string s = "";
        while (n > 0) {
            n--;
            int mod = (n % 26);
            s += 'A' + mod;
            n /= 26;
        }
        reverse(s.begin(), s.end());
        return s;
    }
};
// @lc code=end
