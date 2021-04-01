/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> v;
        map<int, bool> m;
        for(auto &i: nums) {
            if(m[i]) {continue;}
            // v.push_back(i);
            m[i] = true;
        }
        return subsets(v);
    }
    vector<vector<int>> subsets(vector<int> &nums) {
        vector<vector<int>> res = {{}};
        for (int i = 0, size = nums.size(); i < size; i++) {
            int len = res.size();
            for (int j = 0; j < len; j++) {
                vector<int> temp = res[j]; //取出1个旧的子集
                temp.push_back(nums[i]); //加入新的元素，组成1个新子集
                res.push_back(temp);     //更新解集
            }
        };
        return res;
    }
};
// @lc code=end

