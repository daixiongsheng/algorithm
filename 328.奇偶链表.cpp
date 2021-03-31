/*
 * @lc app=leetcode.cn id=328 lang=cpp
 *
 * [328] 奇偶链表
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
    ListNode *oddEvenList(ListNode *head) {
        if (!head || !head->next)
            return head;
        auto p = head->next;
        auto even = head->next;
        auto pre = head;
        while (p && p->next) {
            pre->next = p->next;
            p->next = p->next->next;
            pre = pre->next;
            p = p->next;
        }
        pre->next = even;
        return head;
    }
};
// @lc code=end
