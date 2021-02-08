/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 */

// @lc code=start
class Solution {
public:
    int rob(vector<int> &nums) {
        int n = nums.size();
        if (n == 0)
            return n;
        if (n == 1) {
            return nums[0];
        }
        if (n == 2) {
            return max(nums[0], nums[1]);
        }
        map<int, int> m;
        m[0] = nums[0];
        m[1] = max(nums[0], nums[1]);
        for (int i = 2; i < n; i++) {
            m[i] = max(m[i - 2] + nums[i], m[i - 1]);
        }
        return max(m[n - 1], m[n - 2]);
    }
};
// @lc code=end
