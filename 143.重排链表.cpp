/*
 * @lc app=leetcode.cn id=143 lang=cpp
 *
 * [143] 重排链表
 */

// @lc code=start

#include "iostream"
#include "vector"
#include "map"

using namespace std;
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    void reorderList(ListNode* head) {
        // 找到中点
        // 反转后面的链表
        // 合并两个链表
        if(!head || !head->next) {
            return;
        }
        ListNode *p = head;
        ListNode *q = head;

        while(q && q->next && q->next->next) {
            q = q->next->next;
            p = p->next;
        }
        q = p;
        ListNode *r = reverseList(p->next);
        merge(head, r, q);
    }

    void merge(ListNode *l, ListNode *r, ListNode *mid) {
        if (!l || !r) return;
        while(l != mid && r) {
            ListNode *t = l;
            ListNode *lt = l->next;
            ListNode *rt = r->next;
            l->next = r;
            r->next = lt;
            l = lt;
            r = rt;
        }
        l->next = r;
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

int main() {
    Solution s;
    ListNode l5(5);
    ListNode l4(4, &l5);
    ListNode l3(3, &l4);
    ListNode l2(2, &l3);
    ListNode l1(1, &l2);
    s.reorderList(&l1);
}