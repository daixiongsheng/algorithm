/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head || !head->next || left == right) {
            return head;
        }
        ListNode *p = new ListNode(0, head);
        ListNode *result = p;
        ListNode *q = p;
        int r = right - left;
        while (left--) {
            q = p;
            p = p->next;
        }
        ListNode *t;
        while(r--) {
            p = p->next;
            t = p;
        }
        t = p->next;
        p->next = nullptr;
        p = t;
        t = q->next;
        q ->next = reverseList(q->next);
        t ->next = p;
        return result->next;
    }
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

