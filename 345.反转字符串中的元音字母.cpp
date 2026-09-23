/*
 * @lc app=leetcode.cn id=345 lang=cpp
 *
 * [345] 反转字符串中的元音字母
 */

// @lc code=start
#include "string"
using namespace std;
using std::string;

class Solution {
  public:
    string reverseVowels(string s) {
        const string vowels = "aeiouAEIOU";
        int i = 0;
        int j = s.size() - 1;
        while (i < j) {
            while (i < j && vowels.find(s[i]) == string::npos) {
                i++;
            }
            while (i < j && vowels.find(s[j]) == string::npos) {
                j--;
            }
            char t = s[i];
            s[i] = s[j];
            s[j] = t;
            i++;
            j--;
        }
        return s;
    }
};

// @lc code=end
#include <iostream>
int main() {
    Solution s;
    string str = "IceCreAm";
    string res = s.reverseVowels(str);
    std::cout << res << std::endl;
    return 0;
}
