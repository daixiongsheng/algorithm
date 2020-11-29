/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */
#include "string"
#include "vector"
#include "iostream"
using std::string;
using std::vector;
using std::cout;
// @lc code=start
class Solution {
public:

    // Solution() {
    //     this->longestCommonPrefix({"flower","flower","flower","flower"});
    // }

    string longestCommonPrefix(vector<string> strs) {
        int minLength = 0;
        if(strs.size() == 0) return "";
        if(strs.size() == 1) return strs[0];
        for(int i = 0; i < strs[0].size(); i++) {
            char c = strs[0][minLength];
            for(const string& s : strs) {
                if(c != s[minLength]){
                    return strs[0].substr(0, minLength);
                }
            }
            minLength++;
        }
        return strs[0].substr(0, minLength);
    }
};
// @lc code=end

int main() {
    new Solution();
    return 0;
}
