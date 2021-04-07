/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
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
  private:
    ListNode *frontPointer;

  public:
    bool isPalindrome(ListNode *head) {
        frontPointer = head;
        return check(head);
    }

    bool check(ListNode *current) {
        if (current) {
            if (!check(current->next)) {
                return false;
            };
            if (current->val != frontPointer->val) {
                return false;
            }
            frontPointer = frontPointer->next;
        }
        return true;
    }
};
// @lc code=end
