/*
 * @lc app=leetcode.cn id=118 lang=cpp
 *
 * [118] 杨辉三角
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> v;
        if(!numRows) {
            return v;
        }
        vector<int> t;
        t.push_back(1);
        v.push_back(t);
        for (int i = 1; i < numRows; i++) {
            vector<int> vv;
            vv.push_back(1);
            for (int j = 1; j < numRows && j < v[i - 1].size(); j++) {
                vv.push_back(v[i - 1][j - 1] + v[i - 1][j]);
            }
            vv.push_back(1);
            v.push_back(vv);
        }
        return v;
    }
};
// @lc code=end

