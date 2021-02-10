/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第N个节点
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *p = head;
        ListNode *q = head;
        int size = 1;
        while(head->next) {
            size++;
            q = head;
            head = head->next;
        }
        if (size == n) {
            return p->next;
        }
        head = p;
        n = size - n;
        while(n--) {
            head = head->next;
        }
        if (head && head->next) {
            head->val = head->next->val;
            head->next = head->next->next;
        } else {
            q->next =  NULL;
        }
        return p;
    }
};
// @lc code=end

