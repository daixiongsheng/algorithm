/*
 * @lc app=leetcode.cn id=67 lang=cpp
 *
 * [67] 二进制求和
 */


#include "iostream"
#include "string"

using namespace std;
// @lc code=start
class Solution {
public:
    string addBinary(string a, string b) {
        string ans;
        int a_l = a.size(), b_l = b.size();
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        int n = max(a_l, b_l), carry = 0;
        for (size_t i = 0; i < n; ++i) {
            carry += i < a_l ? (a.at(i) == '1') : 0;
            carry += i < b_l ? (b.at(i) == '1') : 0;
            ans.push_back((carry % 2) ? '1' : '0');
            carry /= 2;
        }

        if (carry) {
            ans.push_back('1');
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
// @lc code=end

