/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */

// @lc code=start
class Solution {
public:
    bool isAnagram(string s, string t) {
        int sa[26] = {0};
        int len1 = s.length();
        int len2 = t.length();
        if (len1 != len2) return false;
        for (int i = 0; i < len1; i++) {
            sa[s[i] - 'a']++;
            sa[t[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++) {
            if (sa[i] != 0) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
