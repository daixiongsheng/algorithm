/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
 */
#include "vector"
#include "iostream"
#include <limits.h>
using std::vector;
using std::cout;

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 1) {
            return nums[0];
        }
        int maxSum = nums[0];
        int preMax = maxSum;

        for(int i = 1, len = nums.size(); i < len; i++) {
            preMax = std::max(preMax + nums[i], nums[i]);
            maxSum = std::max(maxSum, preMax);
        }
        return maxSum;
    }
};
// @lc code=end

