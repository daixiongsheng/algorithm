/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        int mL = 1 + this->maxDepth(root->left);
        int mR = 1 + this->maxDepth(root->right);
        if(abs(mL - mR) > 1) {
            return false;
        }
        bool bl = this->isBalanced(root->left);
        bool br = this->isBalanced(root->right);
        return bl && br;
    }
    int maxDepth(TreeNode *root) {
        if (!root) {
            return 0;
        }
        int mL = 1 + maxDepth(root->left);
        int mR = 1 + maxDepth(root->right);
        return mR > mL ? mR : mL;
    }
};
// @lc code=end

