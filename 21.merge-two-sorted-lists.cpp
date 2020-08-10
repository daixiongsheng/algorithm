/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
 */

// @lc code=start

//Definition for singly-linked list.
//struct ListNode {
//    int val;
//    ListNode *next;
//
//    ListNode() : val(0), next(nullptr) {}
//
//    ListNode(int x) : val(x), next(nullptr) {}
//
//    ListNode(int x, ListNode *next) : val(x), next(next) {}
//};

class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *ret = new ListNode();
        ListNode *p = ret;
        while (l1 && l2) {
            int val1 = l1->val;
            int val2 = l2->val;
            if (val1 > val2) {
                p->next = new ListNode(val2);
                l2 = l2->next;
            } else {
                p->next = new ListNode(val1);
                l1 = l1->next;
            }
            p = p->next;
        }
        if (l1) {
            p->next = l1;
        }

        if (l2) {
            p->next = l2;
        }

        return ret->next;
    }
};
// @lc code=end

