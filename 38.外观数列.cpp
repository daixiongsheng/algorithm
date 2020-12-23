/*
 * @lc app=leetcode.cn id=38 lang=cpp
 *
 * [38] 外观数列
 */

#include<vector>
#include<string>
#include<iostream>

using std::vector;
using std::string;
// @lc code=start
class Solution {
public:
    string countAndSay(int n) {
        string v[30];
        v[0] = "1";
        v[1] = "11";
        v[2] = "21";
        string r = "";
        for(int i = 3; i < 30; i++) {
            string s = v[i-1];
            char pre = s[0];
            char cur = '0';
            int length = 0;
            for(int j = 0, len = s.length(); j < len; j++){
                cur = s[j];
                if(pre != cur) {
                    r += std::to_string(length) + pre;
                    pre = cur;
                    length = 0;
                }
                length++;
            }
            if(pre != cur) {
                r += 1 - '0' + cur;
            } else {
                r += std::to_string(length) + pre;
            }
            v[i] = r;
            if(i==n) {
                return v[n-1];
            }
            r = "";
        }
        return v[n-1];
    }
};
// @lc code=end

int main(){
    (new Solution())->countAndSay(4);
}