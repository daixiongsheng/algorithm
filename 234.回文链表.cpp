/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
  public:
    bool isPalindrome(ListNode *head) {
        if (!head || !head->next)
            return true;
        long double s1 = 0, s2 = 0, t = 1;
        while (head) {
            s1 = s1 * 10 + head->val;
            s2 = s2 + t * head->val;
            t *= 10;
            head = head->next;
        }
        return s1 == s2;
    }
};
// @lc code=end
