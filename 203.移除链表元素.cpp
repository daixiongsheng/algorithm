/*
 * @lc app=leetcode.cn id=203 lang=cpp
 *
 * [203] 移除链表元素
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
    ListNode *removeElements(ListNode *head, int val) {
        if (!head)
            return head;
        ListNode *cur = head;
        ListNode *next = head->next;
        while (next) {
            if (next->val == val) {
                cur->next = next->next;
            } else {
                cur = cur->next;
            }
            next = next->next;
        }
        if (head->val == val) {
            return head->next;
        }
        return head;
    }
};
// @lc code=end
