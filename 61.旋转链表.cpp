/*
 * @lc app=leetcode.cn id=61 lang=cpp
 *
 * [61] 旋转链表
 */

// @lc code=start
#include "iostream"
#include "map"
#include "vector"

using namespace std;
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
    ListNode *rotateRight(ListNode *head, int k) {
        if (!head || !head->next || k == 0)
            return head;
        ListNode *pre = head;
        ListNode *next = head->next;
        int n = 1;
        while (true) {
            n++;
            pre = pre->next;
            next = next->next;
            if (!next) {
                pre->next = head;
                next = head;
                break;
            }
        }
        int r = n - (k % n);
        pre = head;
        while (r--) {
            pre = next;
            next = next->next;
        }
        pre->next = nullptr;
        return next;
    }
};
// @lc code=end
