/*
 * @lc app=leetcode.cn id=349 lang=cpp
 *
 * [349] 两个数组的交集
 */
#include "map"
#include "set"
#include "vector"
using namespace std;

// @lc code=start
class Solution {
  public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
        map<int, int> count;
        for (auto i : nums1) {
            count[i] = 1;
        }
        vector<int> ret;
        for (auto i : nums2) {
            if (count.find(i) != count.end()) {
                ret.push_back(i);
                count.erase(i);
            }
        }

        return ret;
    }
};
// @lc code=end
