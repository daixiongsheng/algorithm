/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
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
    //   只交换了值
    ListNode *swapPairs1(ListNode *head) {
        if (!head || !head->next)
            return head;
        ListNode *cur = head, *next = head->next;
        while (cur && next) {
            int t = cur->val;
            cur->val = next->val;
            next->val = t;
            if (next->next)
                next = next->next->next;
            if (cur->next)
                cur = cur->next->next;
        }
        return head;
    }
    // 交换节点
    ListNode *swapPairs(ListNode *head) {
        if(!head || !head->next){
            return head;
        }
        ListNode *next = head->next;
        head->next = swapPairs(next->next);
        next->next = head;
        return next;
    }
};
// @lc code=end
