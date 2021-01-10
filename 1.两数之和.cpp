/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */
#include "vector"
#include "map"
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> m;
        for (int i = 0, len = nums.size(); i < len; i++) {
            int r = target - nums[i];
            if (m.count(r)) {
                return {m[r], i};
            }
            else {
                m[nums[i]] = i;
            }
        }
        return {};
    }
};
// @lc code=end

