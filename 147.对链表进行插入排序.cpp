/*
 * @lc app=leetcode.cn id=147 lang=cpp
 *
 * [147] 对链表进行插入排序
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
    ListNode *insertionSortList(ListNode *head) {
        if(!head || !head->next) return head;
        ListNode *result = new ListNode(0, head);
        ListNode *p = head->next;
        head->next = nullptr;
        ListNode *next = p->next;
        while (p) {
            p->next = nullptr;
            insert(result, p);
            p = next;
            next = next ? next->next : nullptr;
        }
        return result->next;
    }

    void insert(ListNode *head, ListNode *node) {
        ListNode *p = head->next;
        ListNode *pre = head;
        while (p) {
            if (p->val > node->val) {
                pre->next = node;
                node->next = p;
                return;
            }
            pre = pre->next;
            p = p->next;
        }
        pre->next = node;
    }
};
// @lc code=end
