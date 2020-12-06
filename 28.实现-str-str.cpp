/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 实现 strStr()
 */

#include "iostream"
#include "string"
using std::string;
// @lc code=start
class Solution {
  public:
    int strStr(string haystack, string needle) {
        if (needle.size() == 0) {
            return 0;
        }
        return this->KMP(haystack, needle);
    }

    inline void findNext(const string &p, int *next) {
        int lent_p = p.size();
        int i = 0, j = -1;
        next[0] = -1;
        if (lent_p == 1) {
            return;
        }
        while (i < lent_p) {
            if (j == -1 || p[i] == p[j]) {
                ++i;
                ++j;
                next[i] = j;
            } else
                j = next[j];
        }
    }
    // https://www.zhihu.com/question/21923021
    inline int KMP(const string &t, const string &p) {
        int i = 0;
        int j = 0;
        const int len_t = t.size();
        const int lent_p = p.size();
        int next[lent_p + 1];
        this->findNext(p, next);

        while (i < len_t && j < lent_p) {
            if (j == -1 || t[i] == p[j]) {
                i++;
                j++;
            } else {
                j = next[j];
            }
        }
        if (j == lent_p) {
            return i - j;
        } else {
            return -1;
        }
    }
};
// @lc code=end

int main() {
    Solution s;
    // std::cout <<"hello while" << std::endl;
    std::cout << "123" << s.strStr("aabaaabaaac", "aabaaac") << std::endl;

    std::cout << "hello while" << std::endl;
    return 0;
}
