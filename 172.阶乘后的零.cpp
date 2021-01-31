/*
 * @lc app=leetcode.cn id=172 lang=cpp
 *
 * [172] 阶乘后的零
 */

// @lc code=start
class Solution {
public:
    int trailingZeroes(int n) {
        // int count = 0;
        // while(n) {
        //     count += n /= 5;
        // }
        // return count;
        int sum = 0;
        for (int i = n; i >= 1; i--) {
            sum += getFiveDivisor(i);
        }
        return sum;
    }

    int getFiveDivisor(int n) {
        int count = 0;
        while (n) {
            int mod = n % 5;
            count += mod == 0 ? 1 : 0;
            if (mod != 0) {
                break;
            }
            n /= 5;
        }
        return count;
    }
};
// @lc code=end
