/*
 * @lc app=leetcode.cn id=148 lang=cpp
 *
 * [148] 排序链表
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
    ListNode *sortList(ListNode *head) {
        auto result = new ListNode(0, head);
        auto p = head;
        int n = 0;
        while (p) {
            n++;
            p = p->next;
        }
        for (int size = 1; size < n; size <<= 1) {
            auto cur = result->next;
            auto tail = result;

            while (cur) {
                auto left = cur;
                auto right = cut(left, size);
                cur = cut(right, size);
                tail->next = mergeTwoLists(left, right);
                while (tail->next) {
                    tail = tail->next;
                }
            }
        }
        return result->next;
    }

    ListNode *cut(ListNode *head, int n) {
        auto p = head;
        while (--n && p) {
            p = p->next;
        }

        if (!p)
            return nullptr;
        auto ret = p->next;
        p->next = nullptr;
        return ret;
    }

    ListNode *mergeTwoLists(ListNode *l, ListNode *r) {
        if (!l || !r) {
            return l ? l : r;
        }
        ListNode *p = new ListNode();
        ListNode *q = p;
        while (l && r) {
            if (l->val < r->val) {
                p->next = l;
                p = p->next;
                l = l->next;
            } else {
                p->next = r;
                p = p->next;
                r = r->next;
            }
        }
        p->next = l ? l : r;
        return q->next;
    }
};
// @lc code=end
