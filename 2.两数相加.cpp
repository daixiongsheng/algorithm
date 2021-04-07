/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
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

// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };

class Solution {
  public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        int f = 0;
        auto result = new ListNode(0);
        auto p = result;
        while (l1 && l2) {
            int n = l1->val + l2->val + f;
            f = n >= 10 ? 1 : 0;
            p->next = new ListNode(f ? n % 10 : n);
            p = p->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        if (f) {
            if (l1) {
                while (l1 && f) {
                    int n = l1->val + f;
                    f = n >= 10 ? 1 : 0;
                    p->next = new ListNode(f ? n % 10 : n);
                    p = p->next;
                    l1 = l1->next;
                }
                if (l1) {
                    p->next = l1;
                }
            }
            if (l2) {
                while (l2 && f) {
                    int n = l2->val + f;
                    f = n >= 10 ? 1 : 0;
                    p->next = new ListNode(f ? n % 10 : n);
                    p = p->next;
                    l2 = l2->next;
                }
                if (l2) {
                    p->next = l2;
                }
            }

            if (f) {
                p->next = new ListNode(f);
            }
        } else {
            p->next = l1 ? l1 : l2;
        }

        return result->next;
    }

    ListNode *reverseList(ListNode *head) {
        if (!head || !head->next)
            return head;
        ListNode *cur = head;
        ListNode *next = head->next;
        cur->next = NULL;
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
