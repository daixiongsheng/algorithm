/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个升序链表
 */

// @lc code=start
//  * Definition for singly-linked list.

#include "iostream"
#include "map"
#include "vector"

using namespace std;

// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };

class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        int n = lists.size();
        if(!n) {
            return nullptr;
        }
        int j = 0;
        while (n > 1) {
            j = 0;
            for (size_t i = 0; i < n; i += 2) {
                lists[j++] = mergeTwoLists(lists[i], i + 1 < n ? lists[i + 1] : nullptr);
            }
            n = j;
        }
        return lists[0];
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

int main() {
    vector<ListNode *> v;
    v.push_back(nullptr);
    v.push_back(nullptr);
    v.push_back(nullptr);
    v.push_back(nullptr);
    v.push_back(nullptr);
    v.push_back(nullptr);
    v.push_back(nullptr);
    v.push_back(nullptr);
    v.push_back(nullptr);
    v.push_back(nullptr);
    Solution s;
    s.mergeKLists(v);
}