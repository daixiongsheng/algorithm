/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start
int arr[100000000] = {0, 1, 2};
class Solution {
  public:
    int climbStairs(int n) {
        int i = 3;
        for (; i <= n; i++) {
            arr[i] = arr[i - 1] + arr[i - 2];
        }
        return arr[n];
    }
};
// @lc code=end
