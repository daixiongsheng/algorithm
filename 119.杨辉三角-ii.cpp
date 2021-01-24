/*
 * @lc app=leetcode.cn id=119 lang=cpp
 *
 * [119] 杨辉三角 II
 */

// @lc code=start
class Solution {
public:
    vector<int> getRow(int numRows) {
        vector<vector<int>> v;
        if(!numRows) {
            return {1};
        }
        vector<int> t;
        t.push_back(1);
        v.push_back(t);
        for (int i = 1; i < numRows + 1; i++) {
            vector<int> vv;
            vv.push_back(1);
            for (int j = 1; j < numRows + 1 && j < v[i - 1].size(); j++) {
                vv.push_back(v[i - 1][j - 1] + v[i - 1][j]);
            }
            vv.push_back(1);
            v.push_back(vv);
        }
        return v[numRows];
    }
};
// @lc code=end

