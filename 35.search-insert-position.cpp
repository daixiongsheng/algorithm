/*
 * @Date         : 2020-06-23
 * @LastEditors  : daixiongsheng
 * @LastEditTime : 2020-07-12
 * @FilePath     : /35.search-insert-position.cpp
 * @Description  :
 */


/*
 * @lc app=leetcode id=35 lang=cpp
 *
 * [35] Search Insert Position
 */
#include <vector>
using std::vector;
// @lc code=start
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0, h = nums.size() - 1;
        int m;
        while (l <= h)
        {
            m = l + (h - l) / 2;
            if (nums[m] < target) {
                l = m + 1;
            }
            else {
                h = m - 1;
            }
        }
        return l;
    }
};
// @lc code=end

