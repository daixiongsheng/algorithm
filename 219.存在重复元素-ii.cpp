/*
 * @lc app=leetcode.cn id=219 lang=cpp
 *
 * [219] 存在重复元素 II
 */

// @lc code=start
class Solution {
  public:
    bool containsNearbyDuplicate(vector<int> &nums, int k) {
        map<int, int> m;
        for (int i = 0; i < nums.size(); i++) {
            if (m.count(nums[i])) {
                if (i - m[nums[i]] > k) {
                    m[nums[i]] = max(m[nums[i]], i);
                }
                else {
                    return true;
                }
            }
            else {
                m[nums[i]] = i;
            }
        }
        return false;
    }
};
// @lc code=end
