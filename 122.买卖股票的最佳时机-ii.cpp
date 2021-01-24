/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 */

// @lc code=start
class Solution {
public:
    // 贪心
    int maxProfit(vector<int>& prices) {
        int sum = 0;
        for(int i = 1; i < prices.size(); i++) {
            if(prices[i - 1] < prices[i]) {
                sum += prices[i] - prices[i - 1];
            }
        }
        return sum;
    }
};
// @lc code=end

