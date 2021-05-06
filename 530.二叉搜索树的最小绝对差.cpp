/*
 * @lc app=leetcode.cn id=530 lang=cpp
 *
 * [530] 二叉搜索树的最小绝对差
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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
    int min = 1e9;
    TreeNode *pre;

  public:
    int getMinimumDifference(TreeNode *root) {
        order(root);
        return min;
    }

    void order(TreeNode *root) {
        if (!root)
            return;
        order(root->left);
        if (pre) {
            int tp = root->val - pre->val;
            min = min < tp ? min : tp;
        }
        pre = root;
        order(root->right);
    }
};
// @lc code=end
