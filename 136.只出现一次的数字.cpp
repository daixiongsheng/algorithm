/*
 * @lc app=leetcode.cn id=136 lang=cpp
 *
 * [136] 只出现一次的数字
 */

// @lc code=start
class Solution {
public:
    int singleNumber(vector<int> &nums) {
        map<int, int> m;
        for (auto i : nums) {
            if (m.count(i)) {
                m[i]++;
            } else {
                m[i] = 1;
            }
        }
        for (auto i : m) {
            if (i.second == 1) {
                return i.first;
            }
        }
        return -1;
    }
};
// @lc code=end
