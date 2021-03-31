/*
 * @lc app=leetcode.cn id=82 lang=cpp
 *
 * [82] 删除排序链表中的重复元素 II
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
    ListNode *deleteDuplicates(ListNode *head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode *p = new ListNode(0, head);
        ListNode *q = p;
        while (p->next && p->next->next) {
            if (p->next->val == p->next->next->val) {
                int x = p->next->val;
                while (p->next && p->next->val == x) {
                    p->next = p->next->next;
                }
            }
            else {
                p = p->next;
            }
        }
        return q->next;
    }
};
// @lc code=end
