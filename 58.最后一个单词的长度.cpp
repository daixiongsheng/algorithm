/*
 * @lc app=leetcode.cn id=58 lang=cpp
 *
 * [58] 最后一个单词的长度
 */
#include <iostream>
#include <string>
#include <regex>
#include <iterator>

using namespace std;

// @lc code=start
class Solution {
public:
	int lengthOfLastWord(string s) {
        s.erase(0, s.find_first_not_of(" "));
        s.erase(s.find_last_not_of(" ") + 1);
		if (s.length() == 0) return 0;
		regex pattern("(\\w+)");
		smatch result;
		string::const_iterator start = s.begin();
		string::const_iterator end = s.end();
		string res;
		while (regex_search(start, end, result, pattern))
		{
			res = result[0];
			start = result[0].second;	//更新搜索起始位置,搜索剩下的字符串
		}
		return res.length();
	}
};
// @lc code=end
