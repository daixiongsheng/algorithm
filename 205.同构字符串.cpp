/*
 * @lc app=leetcode.cn id=205 lang=cpp
 *
 * [205] 同构字符串
 */

// @lc code=start
class Solution {
  public:
    bool isIsomorphic(string s, string t) {
        // hash
        unordered_map<char, char> s2t;
        unordered_map<char, char> t2s;

        int i = 0, len = s.length();
        while (i < len) {
            char x = s[i], y = t[i];
            if ((s2t.count(x) && s2t[x] != y) || (t2s.count(y) && t2s[y] != x)) {
                return false;
            }
            s2t[x] = y;
            t2s[y] = x;
            i++;
        }
        return true;
    }
};
// @lc code=end
