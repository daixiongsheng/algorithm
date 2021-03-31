/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
 */

#include "iostream"
#include "vector"
#include "map"

using namespace std;
// @lc code=start
//
// Definition for singly-linked list.
/* struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
} */;

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (!head || !head->next)
            return nullptr;
        if (head->next == head)
            return head;
        bool found = false;
        ListNode *p1 = head, *p2 = head;
        while (p1 && p2 && p2->next) {
            p1 = p1->next;
            p2 = p2->next->next;
            if (p1 && p2 && p1 == p2) {
                found = true;
                break;
            }
        }
        if(!found) {
            return nullptr;
        }
        p1 = head;
        while (p1 != p2) {
            p1 = p1->next;
            p2 = p2->next;
        }
        return p2;
    }
};
// @lc code=end
