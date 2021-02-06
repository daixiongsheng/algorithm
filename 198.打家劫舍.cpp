/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 */

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        int a = 0, b = 0;
        int n = nums.size();
        for(int i = 0; i < n - 1; i+= 2) {
            a += nums[i];
            b += nums[i+1];
        }
        if(n % 2) {
            a += nums[n - 1];
        }
        return a > b ? a : b;
    }
};
// @lc code=end

