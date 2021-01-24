/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        if (!root)
            return true;
        return this->isSameTree(root->left, root->right);
    }
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if (!p && !q) {
            return true;
        }
        if ((!p && q) || (p && !q)) {
            return false;
        }
        if (p->val != q->val) {
            return false;
        }
        if (isSameTree(p->left, q->right)) {
            return isSameTree(p->right, q->left);
        }
        return false;
    }
};
// @lc code=end
