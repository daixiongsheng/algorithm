/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n <= 1)
            return 0;
        int mi = prices[0], ma = 0;
        for (int i = 0; i < n; i++)
        {
            int tp = prices[i] - mi;
            ma = ma > tp ? ma : tp;
            mi = mi < prices[i] ? mi : prices[i];
        }
        return ma;
    }
};
// @lc code=end

