/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
 */

#include "iostream"
#include "vector"
#include "map"

using namespace std;
// @lc code=start
// *
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
    ListNode *mergeTwoLists(ListNode *l, ListNode *r) {
        if (!l || !r) {
            return l ? l: r;
        }
        ListNode *p = new ListNode();
        ListNode *q = p;
        while (l && r) {
            if(l->val < r->val) {
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


// int main() {
//     Solution s;
//     ListNode l5(4);
//     ListNode l4(2, &l5);
//     ListNode l3(1, &l4);

//     ListNode l2(4);
//     ListNode l1(3, &l2);
//     ListNode l0(, &l1);

//     s.mergeTwoLists(&l3, &l0);
// }