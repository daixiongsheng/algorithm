/*
 * @lc app=leetcode.cn id=350 lang=cpp
 *
 * [350] 两个数组的交集 II
 */
#include "map"
#include "set"
#include "vector"
using namespace std;

// @lc code=start
class Solution {
  public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2) {
        map<int, int> count;
        for (auto i : nums1) {
            count[i]++;
        }
        vector<int> ret;
        for (int i = 0; i < nums2.size(); i++) {
            if (count.find(nums2[i]) != count.end() && count[nums2[i]] > 0) {
                ret.push_back(nums2[i]);
                count[nums2[i]]--;
            }
        }

        return ret;
    }
};
// @lc code=end
