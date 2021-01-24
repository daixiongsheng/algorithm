/*
 * @lc app=leetcode.cn id=125 lang=cpp
 *
 * [125] 验证回文串
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(string s) {
        // replace(_ExecutionPolicy&& __exec, _ForwardIterator __first, _ForwardIterator __last, const _Tp& __old_value,
        // const _Tp& __new_value)
        if(s.length() <= 1) return true;
        int h = s.length() - 1;
        int i =0;
        while (i < h) {
            while((!isalpha(s[i]) && !isdigit(s[i])) && i < h) {
                i++;
            }
            while((!isalpha(s[h]) && !isdigit(s[h])) && i < h) {
                h--;
            }
            if(
                (s[h] >= 'a' && s[i] <'a' && s[i] + 32 == s[h])
                || (s[h] < 'a' && s[i] >='a' && s[h] + 32 == s[i])
                || (s[i] == s[h])
            ) {
                i++, h--;
                continue;
            }
            else {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

