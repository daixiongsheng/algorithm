/*
 * @lc app=leetcode.cn id=1143 lang=cpp
 *
 * [1143] 最长公共子序列
 */
#include "iostream"
#include "vector"
#include "algorithm"
#include "queue"
#include "map"

using namespace std;

// @lc code=start
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> v;
        int len1 = text1.length();
        int len2 = text2.length();
        vector<int> vv;
        for (int i = 0; i <= len2; i++) {
            vv.push_back(0);
        }
        for (int i = 0; i <= len1; i++) {
            v.push_back(vv);
        }
        for (int i = 0; i <= len1; i++) {
            v[i][0] = 0;
        }

        for (int i = 1; i <= len1; i++) {
            for (int j = 1; j <= len2; j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    v[i][j] = v[i - 1][j - 1] + 1;
                } else {
                    v[i][j] = std::max(v[i - 1][j], v[i][j - 1]);
                }
            }
        }
        return v[len1][len2];
    }
};

// @lc code=end

