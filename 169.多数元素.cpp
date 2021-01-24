/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素
 */

// @lc code=start
class Solution {
public:
    int majorityElement(vector<int> &nums) {
        map<int, int> m;
        for (auto i : nums) {
            if (m.count(i)) {
                m[i]++;
            } else {
                m[i] = 1;
            }
        }
        int ma = 0;
        int ii = nums[0];
        for (auto i : m) {
            if (i.second >= ma) {
                ma = i.second;
                ii = i.first;
            }
        }
        return ii;
    }
};
// @lc code=end
