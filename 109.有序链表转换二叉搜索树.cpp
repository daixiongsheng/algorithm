/*
 * @lc app=leetcode.cn id=109 lang=cpp
 *
 * [109] 有序链表转换二叉搜索树
 */

// @lc code=start
#include "iostream"
#include "vector"
#include "map"

// using namespace std;
// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };

// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right)
//         : val(x), left(left), right(right) {}
// };

class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        if(!head) return nullptr;
        if (!head->next) {
            return new TreeNode(head->val);
        }
        ListNode *pre = head;
        ListNode *p = head->next;
        ListNode *q = head->next->next;
        while (q && q->next) {
            pre = pre->next;
            p = p->next;
            q = q->next->next;
        }
        pre->next = nullptr;
        return new TreeNode(p->val, sortedListToBST(head), sortedListToBST(p->next)); ;
    }

    // 建树
    TreeNode *sortedListToBST1(ListNode *head) {
        if(!head) return nullptr;
        TreeNode *root = new TreeNode(head->val);
        head = head->next;
        while (head) {
            balanceTree(root, head->val);
            if (!isBalanced(root)) {
                root = reBalance(root);
            }
            head = head->next;
        }
        return root;
    }

    TreeNode *reBalance(TreeNode *root) {
        int hl = height(root->left);
        int hr = height(root->right);
        TreeNode *rl = root->left;
        TreeNode *rr = root->right;
        if (hl>hr) {
            root->left = rl->right;
            rl->right = root;
            root = rl;
        }
        else {
            root->right = rr->left;
            rr->left = root;
            root = rr;
        }
        return root;
    }

    bool isBalanced(TreeNode *root) {
        return abs(height(root->left) - height(root->right)) <= 1;
    }

    int height(TreeNode *root) {
        if (!root)
            return 0;
        return 1 + max(height(root->left), height(root->right));
    }

    void balanceTree(TreeNode *root, int val) {
        if (root->val <= val) {
            if (root->right) {
                balanceTree(root->right, val);
                root->right = isBalanced(root->right) ? root->right: reBalance(root->right);
            } else {
                root->right = new TreeNode(val);
            }
        } else {
            if (root->left) {
                balanceTree(root->left, val);
                root->left = isBalanced(root->left) ? root->left: reBalance(root->left);
            } else {
                root->left = new TreeNode(val);
            }
        }
    }
};
// @lc code=end

int main() {
    Solution s;
    ListNode l6(6);
    ListNode l5(5, &l6);
    ListNode l4(4, &l5);
    ListNode l3(3, &l4);
    ListNode l2(2, &l3);
    ListNode l1(1, &l2);
    ListNode l0(0, &l1);
    s.sortedListToBST(&l0);

}