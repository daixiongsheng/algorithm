/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
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
    ListNode *reverseList(ListNode *head) {
        if (!head || !head->next)
            return head;
        ListNode *cur = head;
        ListNode *next = head->next;
        cur -> next = NULL;
        ListNode *p = cur->next, *q = next->next;
        while (next) {
            cur->next = p;
            q = next->next;
            next->next = cur;
            p = cur;
            cur = next;
            next = q;
        }
        return cur;
    }
};
// @lc code=end
