/*
 * @lc app=leetcode.cn id=228 lang=cpp
 *
 * [228] 汇总区间
 */
#include "iostream"
#include "string"
#include "vector"
using namespace std;
// @lc code=start
class Solution {
  public:
    vector<string> summaryRanges(vector<int> &nums) {
        vector<string> v;
        int n = nums.size();
        if (n == 0) return v;
        string start = to_string(nums[0]);
        string end = start;
        if (n == 1)  {
            v.push_back(start);
            return v;
        }
        bool found = false;
        for (int i = 1; i < n; i++) {
            if (nums[i - 1] + 1 != nums[i]) {
                if (i == n - 1) {
                    found = true;
                }
                if (nums[i - 1] != start[0]) {
                    if (start == to_string(nums[i - 1])) {
                        v.push_back(start);
                    }
                    else {
                        v.push_back(start + "->" + to_string(nums[i - 1]));
                    }
                } else {
                    v.push_back(start);
                }
                start = to_string(nums[i]);
            }
        }
        end = to_string(nums[n - 1]);
        if (start != end) {
            v.push_back(start + "->" + end);
        } else {
            v.push_back(start);
        }
        return v;
    }
};
// @lc code=end
