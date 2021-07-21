/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */
#include "algorithm"
#include "iostream"
#include "map"
#include "queue"
#include "vector"

using namespace std;
// @lc code=start
class Solution {
  public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        std::sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        int max = 0, min = 0, n = nums.size();
        for (auto &i : nums) {
            if (i > max)
                max = i;
            if (i < min)
                min = i;
        }
        map<string, bool> m;
        int sum2;
        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                sum2 = nums[j] + nums[i];
                if ((sum2 > 0 && sum2 + min > 0) ||
                    (sum2 < 0 && sum2 + max < 0)) {
                    continue;
                }
                if (m[to_string(nums[i]) + to_string(nums[j])] &&
                    m[to_string(nums[j]) + to_string(nums[i])]) {
                    continue;
                }
                for (int k = j + 1; k < n; k++) {
                    if (sum2 + nums[k] == 0) {
                        m[to_string(nums[i]) + to_string(nums[j])] = true;
                        m[to_string(nums[i]) + to_string(nums[k])] = true;
                        m[to_string(nums[j]) + to_string(nums[k])] = true;

                        m[to_string(nums[j]) + to_string(nums[i])] = true;
                        m[to_string(nums[k]) + to_string(nums[i])] = true;
                        m[to_string(nums[k]) + to_string(nums[j])] = true;
                        result.push_back({nums[i], nums[j], nums[k]});
                        break;
                    }
                }
            }
        }
        return result;
    }
};
// @lc code=end
