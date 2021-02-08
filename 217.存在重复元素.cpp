/*
 * @lc app=leetcode.cn id=217 lang=cpp
 *
 * [217] 存在重复元素
 */

// @lc code=start
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> m;
        for(auto i : nums) {
            if(m.count(i)) {
                return true;
            }
            m.insert(i);
        }
        return false;
    }
};
// @lc code=end

