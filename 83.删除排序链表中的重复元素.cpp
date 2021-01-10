/*
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] 删除排序链表中的重复元素
 */

// @lc code=start

// Definition for singly-linked list.

#include "iostream"
#include "set"
#include "map"

// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };

using namespace std;
class Solution {
public:
// 112
    ListNode* deleteDuplicates(ListNode* head) {
        set<int> m;
        if(!head || !head->next) {
            return head;
        }
        ListNode* current = head->next;
        ListNode* pre = head;
        m.insert(pre->val);
        while (current) {
            if(m.count(current->val)) {
                current = current->next;
                pre->next = current;
            }
            else {
                m.insert(current->val);
                pre = pre->next;
                current = current->next;
            }
        }
        return head;
    }
};
// @lc code=end
