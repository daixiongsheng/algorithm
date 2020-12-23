/*
 * @lc app=leetcode.cn id=66 lang=cpp
 *
 * [66] 加一
 */
#include "iostream"
#include "vector"

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int len = digits.size();
        int flag = 1;
        vector<int> v;
        if (len == 1) {
            int r = digits[0] + 1;
            if (r >= 10) {
                v.push_back(1);
                v.push_back(0);
            } else {
                v.push_back(r);
            }
            return v;
        }
        for(int i = len - 1; i >= 0; i--) {
            int a = digits[i] + flag;
            if (a >= 10) {
                v.insert(v.begin(), 0);
                if (i == 0) {
                    v.insert(v.begin(), 1);
                }
                flag = 1;
            } else {
                flag = 0;
                v.insert(v.begin(), a);
            }
        }
        return v;
    }

};
// @lc code=end

