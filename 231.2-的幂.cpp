/*
 * @lc app=leetcode.cn id=231 lang=cpp
 *
 * [231] 2的幂
 */

// @lc code=start
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n == 0) return false;
        if (n == 1) return true;
        long f = 2;
        for (int i = 0; i < n; i++) {
            if (f == n) {
                return true;
            }
            if (f >n) return false;
            f *= 2;
        }
        return false;
    }
};
// @lc code=end

