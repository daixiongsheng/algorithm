/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
 */
#include "iostream"
#include "map"
#include "vector"

using namespace std;
// @lc code=start
// Definition for singly-linked list.

// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };

class Solution {
  public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        //
        if (!head || !head->next)
            return head;
        int n = k;
        ListNode *p = head;
        ListNode *temp = new ListNode();
        ListNode *ret = temp;
        ListNode *q = head;
        while (p) {
            while (--n && p) {
                p = p->next;
            }
            if (n != 0 || !p) {
                return ret->next;
            }
            q = p->next;
            p->next = nullptr;
            temp->next = reverseList(head);
            temp = head;
            head->next = q;
            head = head->next;
            p = q;
            n = k;
        }
        return ret->next;
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
// int main() {
//     Solution s;
//     ListNode l5(5);
//     ListNode l4(4, &l5);
//     ListNode l3(3, &l4);
//     ListNode l2(2, &l3);
//     ListNode l1(1, &l2);
//     s.reverseKGroup(&l1, 2);
// }