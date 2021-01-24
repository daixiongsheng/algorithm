/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // 让两个指针走相同的距离
        ListNode *p = headA;
        ListNode *q = headB;
        while (q != p) {
            p = p ? p->next : headB;
            q = q ? q->next : headA;
        }
        return q;
    }
};
// @lc code=end

