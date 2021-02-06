/*
 * @lc app=leetcode.cn id=190 lang=cpp
 *
 * [190] 颠倒二进制位
 */

// @lc code=start
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t r = 0;
        int t=32;
        while (t--) {
            r<<=1;
            r += n&1;
            n>>=1;
        }
        return r;
    }
};
// @lc code=end

