/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */
#include "algorithm"
#include "iostream"
#include "map"
#include "queue"
#include "vector"

using namespace std;
// @lc code=start
class Solution {
  private:
    map<int, int> m;

  public:
    int coinChange(vector<int> &coins, int amount) { return dp(amount, coins); }

    int dp(int n, vector<int> &coins) {
        if (m.count(n)) {
            return m[n];
        }
        if (n < 0)
            return -1;
        if (n == 0)
            return 0;
        int res = INT32_MAX;
        for (auto &i : coins) {
            int sub = dp(n - i, coins);
            if (sub == -1) {
                continue;
            } else {
                res = min(res, 1 + sub);
            }
        }
        res = res != INT32_MAX ? res : -1;
        m[n] = res;
        return res;
    }
};
// @lc code=end
