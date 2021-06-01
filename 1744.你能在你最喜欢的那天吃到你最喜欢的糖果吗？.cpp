/*
 * @lc app=leetcode.cn id=1744 lang=cpp
 *
 * [1744] 你能在你最喜欢的那天吃到你最喜欢的糖果吗？
 */

// @lc code=start
class Solution {
public:
    vector<bool> canEat(vector<int>& candiesCount, vector<vector<int>>& queries) {
        int l = queries.size();
        int lcp = candiesCount.size();
        vector<long long> v;
        v.push_back(candiesCount[0]);
        vector<bool> answer;
        int i = 1;
        for (; i< lcp; ++i) {
            v.push_back(v[i - 1] + candiesCount[i]);
            // candiesCount[i] = candiesCount[i - 1] + candiesCount[i];
        }
        i = 0;
        for (;i < l; ++i) {
            answer.push_back(false);
            long long tp = queries[i][0];
            long long day = queries[i][1];
            long long capp = queries[i][2];
            if (tp == 0) {
                answer[i] = day < v[tp];
                continue;
            }
            if (day >= v[tp] ||
                (day + 1)* capp <= v[tp] - (v[tp] - v[tp -1]))  {
                answer[i] = false;
            } else {
                answer[i] = true;
            }
        }
        return answer;
    }
};
// @lc code=end

