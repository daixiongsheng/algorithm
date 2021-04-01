/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */
#include "algorithm"
#include "iostream"
#include "map"
#include "vector"

using namespace std;
// @lc code=start
class Solution {
public:
    // vector<vector<int>> subsets(vector<int> &nums) {
    //     vector<vector<int>> res = {{}};
    //     for (int i = 0, size = nums.size(); i < size; i++) {
    //         int len = res.size();
    //         for (int j = 0; j < len; j++) {
    //             vector<int> temp = res[j]; //取出1个旧的子集
    //             temp.push_back(nums[i]); //加入新的元素，组成1个新子集
    //             res.push_back(temp);     //更新解集
    //         }
    //     };
    //     return res;
    // }
    vector<vector<int>> subsets(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        result.push_back({});
        int n = nums.size();
        int idx = 0;
        int preStart = 0;
        int preEnd = n - 1;
        while (idx < n) {
            int next = 0;
            for (size_t index = 0; index < n - idx; index++) {
                auto num = nums[index];
                for (int i = preStart; i <= preEnd && i < result.size(); i++)
                {
                    auto v = result[i];
                    if (count(v.begin(), v.end(), num) ||
                        v.size() && v[0] < num) {
                        continue;
                    }
                    vector<int> vec;
                    vec.push_back(num);
                    for (auto &p : v) {
                        vec.push_back(p);
                    }
                    result.push_back(vec);
                }
                if (index == 0)
                    next = result.size();
                preStart += result[result.size() - 1].size() - 1;
            }
            preStart = next;
            preEnd = result.size() - 1;
            idx++;
        }
        return result;
    }
};
// @lc code=end

int main() {
    Solution s;
    vector<int> v = {1, 2, 3};
    s.subsets(v);
}