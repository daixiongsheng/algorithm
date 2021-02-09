/*
 * @lc app=leetcode.cn id=202 lang=cpp
 *
 * [202] 快乐数
 */
#include "set"
#include "iostream"
using namespace std;
// @lc code=start
class Solution {
public:
    bool isHappy(int n) {
        set<int> s({4, 16, 37, 58, 89, 145, 42, 20});
        while (n != 1 && !s.count(n)) {
            n = next(n);
        }
        return n == 1;
    }

    int next(int n) {
        int sum = 0;
        while (n) {
            int d = n % 10;
            sum += d * d;
            n /= 10;
        }
        return sum;
    }
};
// @lc code=end

