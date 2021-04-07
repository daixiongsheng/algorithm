/*
 * @lc app=leetcode.cn id=86 lang=cpp
 *
 * [86] 分隔链表
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
    ListNode *partition(ListNode *head, int x) {
        if (!head || !head->next)
            return head;
        auto result = new ListNode(0);
        auto q = head;
        auto p = result;
        ListNode *max = nullptr;
        while (q) {
            if (q->val < x && max) {
                auto tp = max->next;
                max->next = new ListNode(q->val);
                max = max->next;
                max->next = tp;
            } else {
                p->next = new ListNode(q->val);
                if (q->val >= x && !max) {
                    max = p;
                }
                p = p->next;
            }
            q = q->next;
        }
        return result->next;
    }
};
// @lc code=end
